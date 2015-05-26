#include "FileException.hpp"
#include <iostream>
#include <string>

const char* FileException::what() const throw()
{
	std::string error = "Error : ";
	switch(err)
	{
		case(FILENAME_ERR):
			error += " can't find the file, check its name and its path.";
			break;
		case(EXIT_ERR):
			error += " the exit instruction is missing.";
			break;
	}
	return ( error.c_str() );
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
