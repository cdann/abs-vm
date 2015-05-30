#include "SyntaxeException.hpp"
#include "LineManager.hpp"
#include <iostream>
#include <string>

bool SyntaxeException::verbose = true;

const char* SyntaxeException::what() const throw()
{
	std::string arg ;
	if (err == ERR_OPSYNT )
		LineManager::args.pop_front();
	if (err == ERR_VALUE)
		arg = LineManager::args.back();
	else
		arg = LineManager::args.front();
	std::string line = LineManager::line;
	std::string text[] = {
		" The instruction\033[1m " + arg + " \33[0m is not known.",
		" The type\033[1m " + arg + "\33[0m doesn't exist.",
		" The value to use is missing.",
		" The instruction\033[1m " + arg +"\33[0m needs no value.",
		" This is not a correct number\033[1m " + arg + "\33[0m",
		" syntaxe error : " + line,
		" The value\033[1m " + arg +"\33[0m in the operand is not in a valid format .",
	};

	std::string error = "Syntaxe Error : line " + LineManager::getNline() + ": " + text[err];
	std::cout << "ouou" <<SyntaxeException::verbose << std::endl;
	if ( SyntaxeException::verbose == true)
		error += "\n" + SyntaxeException::show_line(line, arg);

	return ( error.c_str() );
}

SyntaxeException::SyntaxeException() throw() : std::exception()
{
}

SyntaxeException::SyntaxeException(SYNT_ERR e) throw() : std::exception()
{
	this->err = e;
}


SyntaxeException::SyntaxeException(SyntaxeException const & src) throw()
{
	*this = src;
}

SyntaxeException			& SyntaxeException::operator=(SyntaxeException const &src)  {
		std::exception::operator=(src);
		return (*this);
}

std::string			SyntaxeException::show_line(std::string line, std::string piece)  {
	//std::cout << LineManager::line << std::endl;
	size_t found;
	std::string st2;

	found = line.find(piece);
			//std::cout << piece << " ** " << line << std::endl;
	if (found != std::string::npos)
	{
		st2 = "\033[33;7;1m" + piece + "\033[0m";
			//std::cout << "rthyth";
			line.replace(found, piece.size(), st2);
		st2 = line + "\n";
		//std::cout << line << std::endl;
		for (size_t i = 0; i < found; i++)
		{
			st2 += " ";
		}
			st2 += "^\n";
	}
	return st2;

}

SyntaxeException::~SyntaxeException() throw()
{
}
