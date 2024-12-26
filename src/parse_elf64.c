#include "../headers/nm.h"

static void get_table64(Elf64_Shdr **symtab, Elf64_Shdr **strtab, Elf64_Ehdr *header, Elf64_Shdr *section_headers, char *shstrtab)
{
	for (int i = 0; i < header->e_shnum; i++) {
		Elf64_Shdr *sh_i = &section_headers[i];
		char *section_name = shstrtab + sh_i->sh_name;
		if (ft_strncmp(section_name, ".symtab", 8) == 0)
			*symtab = sh_i;
		if (ft_strncmp(section_name, ".strtab",8) == 0)
			*strtab = sh_i;
	}
}

static char retrieve_letter(int bind, int type, char* shstrtab, Elf64_Shdr *section_headers, Elf64_Sym *sym)
{
	char letter;
	Elf64_Shdr *section = NULL;
	char *section_name = NULL;

	letter = '?';
	if (bind == STB_WEAK)
	{
		if (type == STT_OBJECT) //weak object
		{
			letter = 'V';
			if (sym->st_shndx == SHN_UNDEF)
				letter = 'v';
		}
		else //weak symbol
		{
			letter = 'W';
			if (sym->st_shndx == SHN_UNDEF)
				letter = 'w';
		}
	}
	else if (sym->st_shndx == SHN_UNDEF)
		letter = 'U';
	else if (sym->st_shndx == SHN_ABS)
		letter = 'A';
	else if (sym->st_shndx == SHN_COMMON && type == STT_COMMON)
		letter = 'C';
	else if (sym->st_shndx < SHN_LORESERVE)
	{
		section = &section_headers[sym->st_shndx];
		section_name = shstrtab + section->sh_name;
		if (ft_strncmp(section_name, ".text", 6) == 0)
			letter = 'T';
		else if (ft_strncmp(section_name, ".plt", 5) == 0)
			letter = 'T';
		else if (ft_strncmp(section_name, ".init", 6) == 0)
			letter = 'T';
		else if (ft_strncmp(section_name, ".fini", 6) == 0)
			letter = 'T';
		else if (ft_strncmp(section_name, ".data", 6) == 0 || ft_strncmp(section_name, ".data1", 7) == 0)
			letter = 'D';
		else if (ft_strncmp(section_name, ".got", 5) == 0)
			letter = 'D';
		else if (ft_strncmp(section_name, ".tdata", 6) == 0)
			letter = 'D';
		else if (ft_strncmp(section_name, ".bss", 5) == 0)
			letter = 'B';
		else if (ft_strncmp(section_name, ".tbss", 5) == 0)
			letter = 'B';
		else if (ft_strncmp(section_name, ".rodata", 8) == 0 || ft_strncmp(section_name, ".rodata1", 9) == 0)
			letter = 'R';
		else if (ft_strncmp(section_name, ".debug", 7) == 0)
			letter = 'N';
		else if ((section->sh_flags & SHF_ALLOC) && (section->sh_flags & SHF_WRITE) && (section->sh_flags & SHF_TLS))
			letter = 'B';
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

t_list *parse_elf64(void *file_map, unsigned long file_size, char *filename){
	Elf64_Ehdr	*header;
	Elf64_Shdr	*section_headers;
	Elf64_Shdr	*symtab = NULL;
	Elf64_Shdr	*strtab = NULL;
	char		*shstrtab;

	//checking correct offset
	header = (Elf64_Ehdr *)file_map;

	if (check_file_format(ELFCLASS64, file_map, file_size, filename) == false)
		return NULL;

	section_headers = (Elf64_Shdr *)(file_map + header->e_shoff);
	shstrtab = file_map + section_headers[header->e_shstrndx].sh_offset;

	get_table64(&symtab, &strtab, header, section_headers, shstrtab);
	if (!symtab || !strtab)
	{
		error(filename, "no symbols");
		return NULL;
	}

	//Get the symbol table and the string table, init the symbol list
	Elf64_Sym	*symbols;
	t_list		*symbol_list = NULL;
	char		*strtab_content;
	int			symbol_count;

	if (symtab->sh_offset >= file_size || strtab->sh_offset >= file_size)
	{
		error(filename, "file format not recognized");
		return NULL;
	}

	symbols = (Elf64_Sym *)(file_map + symtab->sh_offset);
	strtab_content = file_map + strtab->sh_offset;
	symbol_count = symtab->sh_size / symtab->sh_entsize;
	//
	//bad sh_size might be a problem
	//
	for (int i = 0; i < symbol_count; i++)
	{
		Elf64_Sym	*sym;
		char		*sym_name;
		char		letter = '?';
		int			type;
		int			bind;

		sym = &symbols[i];
		sym_name = strtab_content + sym->st_name;
		type = ELF64_ST_TYPE(sym->st_info);
		bind = ELF64_ST_BIND(sym->st_info);

		if (type == STT_FILE || (bind == STB_LOCAL && sym->st_shndx == SHN_UNDEF) || !sym_name || sym_name[0] == '\0')
			continue;
		letter = retrieve_letter(bind, type, shstrtab, section_headers, sym);
		list_store_sym_data(&symbol_list, letter, sym_name, sym->st_value);
		if (1 == 0){
			Elf64_Shdr *section = &section_headers[sym->st_shndx];
			char *section_name = shstrtab + section->sh_name;
			print_info_section(section_name, sym_name, section, bind, letter);
		}
	}
	return symbol_list;
}
