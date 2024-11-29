#include "../headers/nm.h"


//open le file
//le map to mem
//

bool is_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] == ELFMAG0 &&
		header->e_ident[EI_MAG1] == ELFMAG1 &&
		header->e_ident[EI_MAG2] == ELFMAG2 &&
		header->e_ident[EI_MAG3] == ELFMAG3)
	{
		return (true);
	}
	return (false);
}


void parse_elf64(void *file_map){
	Elf64_Ehdr *header = (Elf64_Ehdr *)file_map;
	Elf64_Shdr *section_headers = (Elf64_Shdr *)(file_map + header->e_shoff);
	char *shstrtab = file_map + section_headers[header->e_shstrndx].sh_offset;

	Elf64_Shdr *symtab = NULL;
	Elf64_Shdr *strtab = NULL;


	for (int i = 0; i < header->e_shnum; i++) {
		Elf64_Shdr *sh_i = &section_headers[i];//get the section header at index i
		char *section_name = shstrtab + sh_i->sh_name; // like doing tab[index] to get the name of the section
		// ft_putstr_fd(section_name, 1);
		// ft_putstr_fd("\n", 1);
		if (ft_strncmp(section_name, ".symtab", 8) == 0)
			symtab = sh_i;
		if (ft_strncmp(section_name, ".strtab",8) == 0)
			strtab = sh_i;
	}

	//from here we have the symbol table and the string table
	//we can now iterate through the symbol table using the same logic from the prev loop

	//Get the symbol table and the string table
	Elf64_Sym *symbols = (Elf64_Sym *)(file_map + symtab->sh_offset);
	char *strtab_content = file_map + strtab->sh_offset;
	int symbol_count = symtab->sh_size / symtab->sh_entsize;
	for (int i = 0; i < symbol_count; i++) {
		Elf64_Sym *sym = &symbols[i];
		char *sym_name = strtab_content + sym->st_name;
		int type = ELF64_ST_TYPE(sym->st_info); //function obj ...
		int bind = ELF64_ST_BIND(sym->st_info); //local or global or "weak"
		// i have no idea how i can get the value of the each symbol ("T", "U", etc...)
		// if (sym->st_shndx == )

		// }
}

void parse_elf32(void *file_map){
	Elf32_Ehdr *header = (Elf32_Ehdr *)file_map;


}

void start_parsing(char *file)
{
	int fd;
	struct stat buf; //structure for fstat
	void *file_map;
	Elf64_Ehdr *header;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening file.\n", 1);
		exit(EXIT_FAILURE);
	}

	if (fstat(fd, &buf) == -1)
	{
		ft_putstr_fd("Error getting file stats.\n", 1);
		exit(EXIT_FAILURE);
	}

	//map file to memory
	file_map = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file_map == MAP_FAILED)
	{
		ft_putstr_fd("Error mapping file to memory.\n", 1);
		exit(EXIT_FAILURE);
	}

	header = (Elf64_Ehdr *)file_map;
	if (is_elf(file_map)){
		if (header->e_ident[EI_CLASS] == ELFCLASS64)
		{
			parse_elf64(file_map);
		}
		else if (header->e_ident[EI_CLASS] == ELFCLASS32)
		{
			parse_elf32(file_map);
		}
		else
		{
			ft_putstr_fd("Unknown ELF class.\n", 1);
		}
	}
	else
	{
		ft_putstr_fd("Not an ELF file.\n", 1);
		munmap(file_map, buf.st_size);
		exit(EXIT_FAILURE);
	}
	munmap(file_map, buf.st_size);
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		start_parsing("a.out");
	}
	if (ac == 2)
	{
		start_parsing(av[1]);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Expecting only one file.\n",1);
		return (1);
	}
	return (0);
}
