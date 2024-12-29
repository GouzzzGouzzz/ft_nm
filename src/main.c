#include "../headers/nm.h"

void start_parsing(char *file)
{
	int fd;
	struct stat buf; //structure for fstat
	void *file_map;
	Elf64_Ehdr *header;
	t_list *symbol_list = NULL;

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
	file_map = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file_map == MAP_FAILED)
	{
		ft_putstr_fd("Error mapping file to memory.\n", 1);
		exit(EXIT_FAILURE);
	}

	header = (Elf64_Ehdr *)file_map;
	if (is_elf(file_map)){
		if (header->e_ident[EI_CLASS] == ELFCLASS64)
			symbol_list = parse_elf64(file_map, buf.st_size, file);
		else if (header->e_ident[EI_CLASS] == ELFCLASS32)
			symbol_list = parse_elf32(file_map, buf.st_size, file);
	}
	else
	{
		error(file, "file format not recognized");
		munmap(file_map, buf.st_size);
		exit(EXIT_FAILURE);
	}
	//sort in ascii order
	if (symbol_list)
	{
		merge_sortASCII(&symbol_list);
		print_symbol_data(symbol_list);
		free_symbol_data(symbol_list);
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
