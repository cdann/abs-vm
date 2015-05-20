#include "StackException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* StackException::what() const throw()
{
	std::string error = "Error : line " + LineManager::getNline() + ": error of stack ";
	return ( error.c_str() );
}

StackException::StackException() throw() : std::exception()
{
}

StackException::StackException(StackException const & src) throw()
{
	*this = src;
}

StackException			& StackException::operator=(StackException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

StackException::~StackException() throw()
{
}
