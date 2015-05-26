#include "FileParser.hpp"
#include "FileException.hpp"
#include <fstream>
#include <string>
#include <iostream>

FileParser::FileParser() {
	std::string 	buffer;
	bool			e;

	while (getline(std::cin, buffer) && buffer != ";;")
	{
		this->lines.push_back(buffer);
		if (buffer == "exit")
			e = true;
	}
	if (!e)
		throw FileException(EXIT_ERR);
}

FileParser::FileParser(char *f) {
	//std::string 	file(f);
	//std::ifstream	filesrc;
	std::string 	buffer;
	bool 	e;
	//std::cout << "<< |" << f << "|" << std::endl;

	std::ifstream filesrc(f, std::ios::in);
	if (filesrc)
	{
	//std::cout<< "bim";
		while (getline(filesrc, buffer))
		{
			if (buffer[0] != '\0' && buffer[0] != ';')
			{
				this->lines.push_back(buffer);
				if (buffer == "exit")
					e = true;
			}
		}
		filesrc.close();
	}
	else
		throw FileException(FILENAME_ERR);
	if (!e)
		throw FileException(EXIT_ERR);
}


FileParser::FileParser(FileParser const &src) {
	*this = src;
}

FileParser::~FileParser() {
}

FileParser				&FileParser::operator=(FileParser const &rhs) {

	this->lines = rhs.lines;
	return *this;
}

int			FileParser::getLine(std::string & line)
{
	if (this->lines.size() == 0)
		return 0;
	line = this->lines.front();
	this->lines.pop_front();
	return (1);
}


std::ostream	&operator<<(std::ostream &o, FileParser const &rhs) {
	static_cast<void>(rhs);
	o << "FileParser";
	return o;
}
