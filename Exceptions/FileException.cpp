#include "FileException.hpp"
#include <iostream>
#include <string>

const char* FileException::what() const throw()
{

	std::string text[] = {
		"The exit instruction is missing.",
		" Can't find the file, check its name and its path.",
	};

		std::string error = "File Error : " + text[err];
		std::cout << error << std::endl;
		return ( error.data() );
}

FileException::FileException(FILE_ERR e) throw() : std::exception()
{
	this->err = e;
}


FileException::FileException() throw() : std::exception()
{
}


FileException::FileException(FileException const & src) throw()
{
	*this = src;
}

FileException			& FileException::operator=(FileException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

FileException::~FileException() throw()
{
}
