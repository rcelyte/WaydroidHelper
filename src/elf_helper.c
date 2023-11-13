#include "elf_helper.h"
#include "log.h"
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

static uintptr_t baseAddr(const char soname[]) {
	// credits to https://github.com/ikoz/AndroidSubstrate_hookingC_examples/blob/dda58a8f8e666c4260024a7845b8475035caa1d6/nativeHook3/jni/nativeHook3.cy.cpp
	if(soname == NULL)
		return (uintptr_t)NULL;

	FILE *f = NULL;
	char line[200] = {0};
	char *state = NULL;
	char *tok = NULL;
	char * baseAddr = NULL;
	if ((f = fopen("/proc/self/maps", "r")) == NULL)
		return (uintptr_t)NULL;
	while (fgets(line, 199, f) != NULL)
	{
		tok = strtok_r(line, "-", &state);
		baseAddr = tok;
		strtok_r(NULL, "\t ", &state);
		strtok_r(NULL, "\t ", &state); // "r-xp" field
		strtok_r(NULL, "\t ", &state); // "0000000" field
		strtok_r(NULL, "\t ", &state); // "01:02" field
		strtok_r(NULL, "\t ", &state); // "133224" field
		tok = strtok_r(NULL, "\t ", &state); // path field

		if (tok != NULL) {
			int i;
			for (i = (int)strlen(tok)-1; i >= 0; --i) {
				if (!(tok[i] == ' ' || tok[i] == '\r' || tok[i] == '\n' || tok[i] == '\t'))
					break;
				tok[i] = 0;
			}
			{
				size_t toklen = strlen(tok);
				size_t solen = strlen(soname);
				if (toklen > 0) {
					if (toklen >= solen && strcmp(tok + (toklen - solen), soname) == 0) {
						fclose(f);
						return (uintptr_t)strtoll(baseAddr,NULL,16);
					}
				}
			}
		}
	}
	fclose(f);
	return (uintptr_t)NULL;
}

void *ElfLoadedSymbol(const char libPath[], const char procName[]) {
	const int libFD = open(libPath, O_RDONLY);
	struct stat lib_stat = {0};
	if(fstat(libFD, &lib_stat) != 0) {
		logLine_err("fstat(\"%s\") failed: %s", libPath, strerror(errno));
		close(libFD);
		return NULL;
	}
	const Elf64_Ehdr *const header = (const Elf64_Ehdr*)mmap(NULL, (size_t)lib_stat.st_size, PROT_READ, MAP_SHARED, libFD, 0); // TODO: unmap?
	if(header == MAP_FAILED) {
		logLine_err("mmap(\"%s\") failed: %s", libPath, strerror(errno));
		close(libFD);
		return NULL;
	}
	assert(header->e_shoff % sizeof(uint64_t) == 0);
	const Elf64_Shdr *const sections = (const Elf64_Shdr*)(const void*)&header->e_ident[header->e_shoff];
	for(const Elf64_Shdr *section = sections, *const sections_end = &sections[header->e_shnum]; section < sections_end; ++section) {
		if(section->sh_type != SHT_SYMTAB)
			continue;
		assert(section->sh_entsize == sizeof(Elf64_Sym));
		const char *stringTable = (const char*)&header->e_ident[((const Elf64_Shdr*)&sections[section->sh_link])->sh_offset];
		assert(section->sh_offset % sizeof(uint64_t) == 0);
		for(const Elf64_Sym *symbol = (const Elf64_Sym*)(const void*)&header->e_ident[section->sh_offset], *const symbols_end = &symbol[section->sh_size / sizeof(*symbol)]; symbol < symbols_end; ++symbol) {
			if(strcmp(&stringTable[symbol->st_name], procName) != 0)
				continue;
			close(libFD);
			return (void*)(baseAddr(libPath) + symbol->st_value);
		}
		break;
	}
	close(libFD);
	return NULL;
}
