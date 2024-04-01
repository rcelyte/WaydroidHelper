#include "elf_helper.h"
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

uintptr_t baseAddr(const char *soname);
void *ElfLoadedSymbol(const char libPath[], const char procName[]) {
	const int libFD = open(libPath, O_RDONLY);
	struct stat lib_stat = {0};
	if(fstat(libFD, &lib_stat) != 0)
		goto fail;
	const Elf64_Ehdr *const header = (const Elf64_Ehdr*)mmap(NULL, (size_t)lib_stat.st_size, PROT_READ, MAP_SHARED, libFD, 0); // TODO: unmap?
	if(header == MAP_FAILED)
		goto fail;
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
	fail:
	close(libFD);
	return NULL;
}
