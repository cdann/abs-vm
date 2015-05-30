#include "LineManager.hpp"
#include "FileException.hpp"
#include "FileParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
		std::string l;
		FileParser *file;
		LineManager TheBoss;

		if (argc  != 1)
			file = new  FileParser(argv[1]);
		else
			file = new  FileParser();
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
				std::cout << "\"" << l <<"\"" << std::endl;
			}
		}

		try{
			if (file->err != VOID)
				throw FileException(file->err);
		} catch (FileException & e)
		{
			std::cout << e.what();
			//std::cout << std::endl;
			if (argc == 2)
				std::cout << "\"" << argv[1] <<"\"" << std::endl;
		}

	return 0;
}
