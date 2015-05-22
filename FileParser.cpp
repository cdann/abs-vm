#include "FileParser.hpp"
#include <fstream>
#include <string>
#include <iostream>

FileParser::FileParser() {
	std::string 	buffer;

	while (getline(std::cin, buffer) && buffer != ";;")
	{
		this->lines.push_back(buffer);
	}
}

FileParser::FileParser(char *f) {
	std::string 	file(f);
	std::ifstream	filesrc;
	std::string 	buffer;


	filesrc.open (file.data(), std::ifstream::in);
	if (filesrc)
	{
		while (getline(filesrc, buffer))
		{
			this->lines.push_back(buffer);
		}
		filesrc.close();
	}
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

std::string			FileParser::getLine()
{
	std::string line;

	if (this->lines.size() == 0)
		return NULL;
	line = this->lines.front();
	this->lines.pop_front();
	return (line);
}


std::ostream	&operator<<(std::ostream &o, FileParser const &rhs) {
	static_cast<void>(rhs);
	o << "FileParser";
	return o;
}
