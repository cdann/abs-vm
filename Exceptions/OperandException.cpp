#include "OperandException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* OperandException::what() const throw()
{
	std::string error = "Error : line " + LineManager::getNline() + ": ";
	switch(err)
	{
		case(MOD_ERR):
			error += " modulo by 0.";
			break;
		case(DIV_ERR):
			error += " division by 0.";
			break;
		case(OVER_ERR):
			error += " overflow error.";
			break;
		case(UNDER_ERR):
			error += " underflow error.";
			break;
	}

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
