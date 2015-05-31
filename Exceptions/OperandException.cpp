#include "OperandException.hpp"
#include "SyntaxeException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* OperandException::what() const throw()
{
	std::string text[] = {
		" modulo by 0.",
		" division by 0.",
		" overflow error.",
		" underflow error.",
		" this type does not exist.",
		" cannot use an empty value."
	};
	std::string error = "\033[1;4mOperand Error\033[0m : line " + LineManager::getNline() + ": "+= text[err];
	if ( SyntaxeException::getverbose() == true)
		error += "\n\033[35m" + LineManager::getLine()+ "\033[0m\n";
	return ( error.c_str() );
}

OperandException::OperandException() throw() : std::exception()
{
}

OperandException::OperandException(OP_ERR e) throw() : std::exception()
{
	this->err = e;
}

OperandException::OperandException(OperandException const & src) throw()
{
	*this = src;
}

OperandException			& OperandException::operator=(OperandException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

OperandException::~OperandException() throw()
{
}
