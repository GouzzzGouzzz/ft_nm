#include "../headers/nm.h"

static void get_table32(Elf32_Shdr **symtab, Elf32_Shdr **strtab, Elf32_Ehdr *header, Elf32_Shdr *section_headers, char *shstrtab)
{
	for (int i = 0; i < header->e_shnum; i++) {
		Elf32_Shdr *sh_i = &section_headers[i];
		char *section_name = shstrtab + sh_i->sh_name;
		if (ft_strncmp(section_name, ".symtab", 8) == 0)
			*symtab = sh_i;
		if (ft_strncmp(section_name, ".strtab",8) == 0)
			*strtab = sh_i;
	}
}

static char retrieve_letter(int bind, char* shstrtab, Elf32_Shdr *section_headers, Elf32_Sym *sym)
{
	char letter;
	Elf32_Shdr *section = NULL;
	char *section_name = NULL;

	letter = '?';
	if (bind == STB_WEAK)
	{
		letter = 'W';
		if (sym->st_shndx == SHN_UNDEF)
			letter = 'w';
	}
	else if (sym->st_shndx == SHN_UNDEF)
		letter = 'U';
	else if (sym->st_shndx == SHN_ABS)
		letter = 'A';
	else if (sym->st_shndx < SHN_LORESERVE)
	{
		section = &section_headers[sym->st_shndx];
		section_name = shstrtab + section->sh_name;
		if (ft_strncmp(section_name, ".text", 6) == 0)
			letter = 'T';
		else if (ft_strncmp(section_name, ".data", 6) == 0)
			letter = 'D';
		else if (ft_strncmp(section_name, ".bss", 5) == 0)
			letter = 'B';
		else if (ft_strncmp(section_name, ".rodata", 8) == 0)
			letter = 'R';
		else if ((section->sh_flags & SHF_ALLOC) && (section->sh_flags & SHF_WRITE))
			letter = 'D';
		else if ((section->sh_flags & SHF_ALLOC) && (section->sh_flags & SHF_EXECINSTR))
			letter = 'T';
		else if ((section->sh_flags & SHF_ALLOC) && !(section->sh_flags & SHF_WRITE))
			letter = 'R';
	}
	if (bind == STB_LOCAL && letter != 'U' && letter != 'A' && letter != 'W' && letter != 'w')
		letter = ft_tolower(letter);
	return (letter);
}

t_list *parse_elf32(void *file_map){
	Elf32_Ehdr	*header;
	Elf32_Shdr	*section_headers;
	Elf32_Shdr	*symtab = NULL;
	Elf32_Shdr	*strtab = NULL;
	char		*shstrtab;

	header = (Elf32_Ehdr *)file_map;
	section_headers = (Elf32_Shdr *)(file_map + header->e_shoff);
	shstrtab = file_map + section_headers[header->e_shstrndx].sh_offset;

	get_table32(&symtab, &strtab, header, section_headers, shstrtab);
	if (!symtab || !strtab)
		return NULL;

	//Get the symbol table and the string table, init the symbol list
	Elf32_Sym	*symbols;
	t_list		*symbol_list = NULL;
	char		*strtab_content;
	int			symbol_count;

	symbols = (Elf32_Sym *)(file_map + symtab->sh_offset);
	strtab_content = file_map + strtab->sh_offset;
	symbol_count = symtab->sh_size / symtab->sh_entsize;

	for (int i = 0; i < symbol_count; i++)
	{
		Elf32_Sym	*sym;
		char		*sym_name;
		char		letter = '?';
		int			type;
		int			bind;

		sym = &symbols[i];
		sym_name = strtab_content + sym->st_name;
		type = ELF32_ST_TYPE(sym->st_info);
		bind = ELF32_ST_BIND(sym->st_info);

		if (type == STT_FILE || (bind == STB_LOCAL && sym->st_shndx == SHN_UNDEF))
			continue;
		letter = retrieve_letter(bind, shstrtab, section_headers, sym);
		list_store_sym_data(&symbol_list, letter, sym_name, sym->st_value);
		if (1 == 0){
			// Elf32_Shdr *section = &section_headers[sym->st_shndx];
			// char *section_name = shstrtab + section->sh_name;
			// print_info_section(section_name, sym_name, section, bind, letter);
		}
	}
	return symbol_list;
}
