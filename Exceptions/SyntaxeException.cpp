#include "SyntaxeException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* SyntaxeException::what() const throw()
{
	std::string error = "Error : line " + LineManager::getNline() + ": Syntax Error";
	return ( error.c_str() );
}

SyntaxeException::SyntaxeException() throw() : std::exception()
{
}


SyntaxeException::SyntaxeException(SyntaxeException const & src) throw()
{
	*this = src;
}

SyntaxeException			& SyntaxeException::operator=(SyntaxeException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

SyntaxeException::~SyntaxeException() throw()
{
}
