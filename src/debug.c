#include "../headers/nm.h"

void print_info_section(char *section_name, char *sym_name, Elf64_Shdr *section, int bind, char letter){
	ft_putstr_fd("sym name     : ",1);
	if (!sym_name)
		ft_putendl_fd("NULL",1);
	else
		ft_putendl_fd(sym_name,1);

	ft_putstr_fd("section name : ",1);
	if (!section_name)
		ft_putendl_fd("NULL",1);
	else
		ft_putendl_fd(section_name,1);

	ft_putstr_fd("section type : ",1);
	if (section == NULL)
		ft_putendl_fd("NULL",1);
	else{
		if (section->sh_type == SHT_NULL)
			ft_putstr_fd("SHT_NULL",1);
		else if (section->sh_type == SHT_PROGBITS)
			ft_putstr_fd("SHT_PROGBITS",1);
		else if (section->sh_type == SHT_SYMTAB)
			ft_putstr_fd("SHT_SYMTAB",1);
		else if (section->sh_type == SHT_STRTAB)
			ft_putstr_fd("SHT_STRTAB",1);
		else if (section->sh_type == SHT_RELA)
			ft_putstr_fd("SHT_RELA",1);
		else if (section->sh_type == SHT_HASH)
			ft_putstr_fd("SHT_HASH",1);
		else if (section->sh_type == SHT_DYNAMIC)
			ft_putstr_fd("SHT_DYNAMIC",1);
		else if (section->sh_type == SHT_NOTE)
			ft_putstr_fd("SHT_NOTE",1);
		else if (section->sh_type == SHT_NOBITS)
			ft_putstr_fd("SHT_NOBITS",1);
		else if (section->sh_type == SHT_REL)
			ft_putstr_fd("SHT_REL",1);
		else if (section->sh_type == SHT_SHLIB)
			ft_putstr_fd("SHT_SHLIB",1);
		else if (section->sh_type == SHT_DYNSYM)
			ft_putstr_fd("SHT_DYNSYM",1);
		else if (section->sh_type == SHT_INIT_ARRAY)
			ft_putstr_fd("SHT_INIT_ARRAY",1);
		else if (section->sh_type == SHT_FINI_ARRAY)
			ft_putstr_fd("SHT_FINI_ARRAY",1);
		else if (section->sh_type == SHT_PREINIT_ARRAY)
			ft_putstr_fd("SHT_PREINIT_ARRAY",1);
		else if (section->sh_type == SHT_GROUP)
			ft_putstr_fd("SHT_GROUP",1);
		else
			ft_putstr_fd("OTHER",1);
		ft_putendl_fd("",1);

		ft_putstr_fd("section flag : ",1);
		if (section->sh_flags & SHF_ALLOC)
			ft_putstr_fd("SHF_ALLOC ",1);
		if (section->sh_flags & SHF_WRITE)
			ft_putstr_fd("SHF_WRITE ",1);
		if (section->sh_flags & SHF_EXECINSTR)
			ft_putstr_fd("SHF_EXECINSTR ",1);
		if (section->sh_flags & SHF_MASKPROC)
			ft_putstr_fd("SHF_MASKPROC ",1);
		if (section->sh_flags & SHF_TLS)
			ft_putstr_fd("SHF_TLS ",1);
		if (section->sh_flags & SHF_COMPRESSED)
			ft_putstr_fd("SHF_COMPRESSED ",1);
		if (section->sh_flags & SHF_OS_NONCONFORMING)
			ft_putstr_fd("SHF_OS_NONCONFORMING ",1);
		if (section->sh_flags & SHF_GROUP)
			ft_putstr_fd("SHF_GROUP ",1);
		if (section->sh_flags & SHF_MASKOS)
			ft_putstr_fd("SHF_MASKOS ",1);
		if (section->sh_flags & SHF_ORDERED)
			ft_putstr_fd("SHF_ORDERED ",1);
		if (section->sh_flags & SHF_EXCLUDE)
			ft_putstr_fd("SHF_EXCLUDE ",1);
		if (section->sh_flags & SHF_MERGE)
			ft_putstr_fd("SHF_MERG",1);
		if (section->sh_flags & SHF_STRINGS)
			ft_putstr_fd("SHF_STRINGS ",1);
		if (section->sh_flags & SHF_INFO_LINK)
			ft_putstr_fd("SHF_INFO_LINK ",1);
		if (section->sh_flags & SHF_LINK_ORDER)
			ft_putstr_fd("SHF_LINK_ORDER ",1);
		if (section->sh_flags & SHF_EXCLUDE)
			ft_putstr_fd("SHF_EXCLUDE ",1);
		ft_putendl_fd("",1);
	}

	ft_putstr_fd("symbols bind : ",1);
	if (bind == STB_GLOBAL)
		ft_putstr_fd("STB_GLOBAL",1);
	else if (bind == STB_WEAK)
		ft_putstr_fd("STB_WEAK",1);
	else if (bind == STB_LOCAL)
		ft_putstr_fd("STB_LOCAL",1);
	else if (bind == STB_NUM)
		ft_putstr_fd("STB_NUM",1);
	else if (bind == STB_LOOS)
		ft_putstr_fd("STB_LOOS",1);
	else if (bind == STB_HIOS)
		ft_putstr_fd("STB_HIOS",1);
	else if (bind == STB_LOPROC)
		ft_putstr_fd("STB_LOPROC",1);
	else if (bind == STB_HIPROC)
		ft_putstr_fd("STB_HIPROC",1);
	ft_putendl_fd("",1);

	ft_putstr_fd("symbol found : ",1);
	ft_putchar_fd(letter,1);
	ft_putendl_fd("",1);
	ft_putendl_fd("",1);
}
