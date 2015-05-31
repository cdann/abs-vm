#include "LineManager.hpp"
#include "FileException.hpp"
#include "SyntaxeException.hpp"
#include "FileParser.hpp"
#include <iostream>

//typedef void (*t_ope)(void);

bool	put_option(int argc, char  *argv[])
{
	std::string ag(argv[1]);
	bool	b;
	int		j = 1;
	//void (*ft_opt)(void);
	//void (*pointeur_4[])() = {SyntaxeException::setverbose};
	std::string opts[] ={"-v", "-p"};
	void (*ft_opt[])() = {SyntaxeException::setverbose, LineManager::setParser};

	while (j < argc - 1)
	{
		b = false;
		for( int i = 0 ; i < 2 ; ++i)
		{
			if (argv[j] == opts[i])
			{
				(*ft_opt[i])();
				b = true;
			}
		}
		if (b == false)
			return b;
		++j;
	}
	return true;
}

void usage(char const *name)
{
	std::cout << "usage: " << name << " [filename]"<< std::endl;
	std::cout << "options: -v, verbose to have explicits errors."<< std::endl;
	std::cout << "options: -p even if your lines has too many space it will work!"<< std::endl;
}

int main(int argc, char  **argv)
{
		std::string l;
		FileParser *file;
		LineManager TheBoss;

		if (argc == 1)
			file = new  FileParser();
		else if (!put_option(argc, argv))
		{
			usage (argv[0]);
			return 0;
		}
		else
			file = new  FileParser(argv[argc - 1]);
		//std::cout << file->err;
		while ((file->getLine(l)) != 0 && LineManager::getOn())
		{
			//std::cout << "--" << l << std::endl;
			try{
			TheBoss.parseLine(l);
			}
			 catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
				//std::cout << "\"" << l <<"\"" << std::endl;
			}
		}

		try{
			if (file->err != VOID)
				throw FileException(file->err);
		} catch (FileException & e)
		{
			std::cout << e.what();
			//std::cout << std::endl;
			if (file->err == FILENAME_ERR && SyntaxeException::getverbose() == true)
				std::cout << "\033[35m" << argv[1] <<"\033[0m" << std::endl;
		}

	return 0;
}
