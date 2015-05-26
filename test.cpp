#include "LineManager.hpp"
#include "FileException.hpp"
#include "FileParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
		std::string l;
		FileParser *file;
		LineManager TheBoss;
	try{
		//std::cout << argc << " " <<argv[0];
		if (argc  != 1)
			file = new  FileParser(argv[1]);
		else
			file = new  FileParser();
		while ((file->getLine(l)) != 0)
		{
			//std::cout << "--" << l << std::endl;
			TheBoss.parseLine(l);
		}
		//TheBoss.parseLine("add");
		//TheBoss.parseLine("push int8(2)");
		//TheBoss.parseLine("add");
		//TheBoss.parseLine("push int8(52)");
		//TheBoss.parseLine("dump");
		//TheBoss.parseLine("assert int8(82)");
	} catch (FileException & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "\"" << argv[1] <<"\"" << std::endl;
	}
	 catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "\"" << l <<"\"" << std::endl;
	}

	return 0;
}
