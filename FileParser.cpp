#include "FileParser.hpp"
#include "FileException.hpp"
#include "ToolBox.hpp"
#include <fstream>
#include <string>
#include <iostream>

FileParser::FileParser() {
	std::string 	buffer;
	bool			e = 0;

	this->err = VOID;
	while (getline(std::cin, buffer) && buffer != ";;")
	{
		this->lines.push_back(buffer);
		if (buffer == "exit")
			e = true;
	}
	if (!e)
		this->err = EXIT_ERR;
	std::cout << std::endl << "_____________________" << "AVM" << "_____________________" << std::endl;

}

FileParser::FileParser(char *f) {
	//std::string 	file(f);
	//std::ifstream	filesrc;
	std::string 	buffer;
	bool 	e = 0;
	//std::cout << "<< |" << f << "|" << std::endl;

	this->err = VOID;
	std::ifstream filesrc(f, std::ios::in);
	if (filesrc)
	{
		while (getline(filesrc, buffer))
		{
			this->checkline(buffer);
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
	{
	//std::cout<< "buum" << FILENAME_ERR << "    ";
		this->err = FILENAME_ERR;

	}
		//throw FileException(FILENAME_ERR);
	if (!e && this->err != FILENAME_ERR)
		this->err = EXIT_ERR;
}

void FileParser::checkline(std::string &line) {
	size_t found = 0;

	if ((found = line.find(";")) != std::string::npos)
	{
		line = line.substr(0, found);
	}
	ToolBox::trim(line);
	//std::cout << "@@@" << line;
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
