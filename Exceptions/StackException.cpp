#include "StackException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* StackException::what() const throw()
{
	std::string text[] = {
		"Not enought values on the stack to make this operation.",
		"Cannot pop on an empty stack.",
	};
	std::string error = "Stack Error : line " + LineManager::getNline() + ": "+= text[err];

	return ( error.c_str() );
}

StackException::StackException() throw() : std::exception()
{
}

StackException::StackException(STACK_ERR e) throw() : std::exception()
{
	this->err = e;
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
