#include "OperandException.hpp"
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
	std::string error = "Operand Error : line " + LineManager::getNline() + ": "+= text[err];

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
