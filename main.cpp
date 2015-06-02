#include "LineManager.hpp"
#include "FileException.hpp"
#include "SyntaxeException.hpp"
#include "FileParser.hpp"
#include <iostream>
# include <list>
//typedef void (*t_ope)(void);

void usage()
{
	std::cout << "usage: ./avm [filename]"<< std::endl;
	std::cout << "options: -v, verbose to have explicits errors."<< std::endl;
	std::cout << "options: -p even if your lines has too many space it will work!"<< std::endl;
}

std::list<std::string>	put_option(int argc, char  *argv[])
{
	std::list<std::string> aglist;
	bool	b;
	int		j = 1;
	std::string opts[] ={"-v", "-p", "-h"};
	void (*ft_opt[])() = {&SyntaxeException::setverbose, &LineManager::setParser, &usage};

	while (j < argc)
	{
		b = false;
		for( int i = 0 ; i < 3 ; ++i)
		{
			if (argv[j] == opts[i])
			{
				(*ft_opt[i])();
				b = true;
			}
		}
		if (b == false)
		{
			aglist.push_back(argv[j]);
		}
		++j;
	}
	return aglist;
}



void		byFile(std::string fileName)
{
	FileParser *file;
	std::string l;
	LineManager TheBoss;
	bool	error = false;

	if (fileName == "")
		file = new  FileParser();
	else
		file = new  FileParser(fileName.c_str());
	while ((file->getLine(l)) != 0 && LineManager::getOn())
	{
		try{
			TheBoss.parseLine(l, error);
		} catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			error = true;
		}
	}

	try{
		if (file->err != VOID)
			throw FileException(file->err);
	} catch (FileException & e)
	{
		std::cout << e.what();
		if (file->err == FILENAME_ERR && SyntaxeException::getverbose() == true)
			std::cout << "\033[35m" << fileName <<"\033[0m" << std::endl;
	}
}

int main(int argc, char  **argv)
{
	std::list<std::string> files;


	files = put_option(argc, argv);
	if (files.empty())
		byFile("");
	for ( std::list<std::string>::iterator it = files.begin() ; it != files.end() ; it++)
	{
		std::cout << "\n ___________ \033[32m" << *it << "\033[0m ___________ \n" << std::endl;
		byFile(*it);
	}
	return 0;
}
