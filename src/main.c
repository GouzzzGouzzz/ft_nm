#include "../headers/nm.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *str_create_error(char *file, char *prev)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(file, "'");
	tmp2 =tmp;
	tmp = ft_strjoin(prev, tmp);
	free(tmp2);
	return tmp;
}

void start_parsing(char *file)
{
	int fd;
	struct stat buf;
	void *file_map;
	Elf64_Ehdr *header;
	t_list *symbol_list = NULL;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			error(file, "Permission denied");
		else if (errno == ENOENT)
		{
			char *tmp;
			tmp = str_create_error(file, "'");
			error(tmp, "No such file");
			free(tmp);
		}
		exit(EXIT_FAILURE);
	}

	if (fstat(fd, &buf) == -1)
	{
		ft_putstr_fd("Error getting file stats.\n", 1);
		exit(EXIT_FAILURE);
	}

	//map file to memory
	file_map = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (S_ISDIR(buf.st_mode))
	{
		char *tmp;
		tmp = str_create_error(file, "Warning: '");
		error(tmp, "\b\b is a directory");
		free(tmp);
		exit(EXIT_FAILURE);
	}
	else if (file_map == MAP_FAILED)
	{
		exit(EXIT_FAILURE);
	}

	header = (Elf64_Ehdr *)file_map;
	if (is_elf(file_map)){
		if (header->e_ident[EI_CLASS] == ELFCLASS64)
			symbol_list = parse_elf64(file_map, buf.st_size, file);
		else if (header->e_ident[EI_CLASS] == ELFCLASS32)
			symbol_list = parse_elf32(file_map, buf.st_size, file);
		else {
			error(file, "file format not recognized");
			munmap(file_map, buf.st_size);
			exit(0);
		}
	}
	else
	{
		error(file, "file format not recognized");
		munmap(file_map, buf.st_size);
		exit(0);
	}
	//sort in ascii order
	if (symbol_list)
	{
		merge_sortASCII(&symbol_list);
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			print_symbol_data(symbol_list, ELFCLASS32);
		else
			print_symbol_data(symbol_list, ELFCLASS64);
		free_symbol_data(symbol_list);
	}
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
