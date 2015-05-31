#include "StackException.hpp"
#include "SyntaxeException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* StackException::what() const throw()
{
	std::string text[] = {
		"Not enought values on the stack to make this operation.",
		"Cannot pop on an empty stack.",
	};
	std::string error = "\033[1;4mStack Error\033[0m : line " + LineManager::getNline() + ": "+= text[err];
	if ( SyntaxeException::getverbose() == true)
		error += "\n\033[35m" + LineManager::getLine()+ "\033[0m\n";

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
