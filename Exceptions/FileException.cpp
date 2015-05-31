#include "FileException.hpp"
#include "SyntaxeException.hpp"
#include <iostream>
#include <string>

const char* FileException::what() const throw()
{

	std::string text[] = {
		"The exit instruction is missing.",
		" Can't find the file, check its name and its path.",
	};

		std::string error = "\033[1;4mFile Error\033[0m : " + text[err];

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
