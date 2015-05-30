#include "AssertException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

const char* AssertException::what() const throw()
{
	std::string error = "Assert Error : line " + LineManager::getNline() + ": The result of Assert is not the result expected.";
	return ( error.c_str() );
}

AssertException::AssertException() throw() : std::exception()
{
}


AssertException::AssertException(AssertException const & src) throw()
{
	*this = src;
}

AssertException			& AssertException::operator=(AssertException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

AssertException::~AssertException() throw()
{
}
