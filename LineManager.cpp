#include "LineManager.hpp"
#include "SyntaxeException.hpp"
#include <vector>

//LineManager	LineManager::Manager;
int LineManager::nline = 0;
/*--------------------------------------------------------*/
/*                       Canonique                        */
/*--------------------------------------------------------*/

LineManager::LineManager() {
	stack = new MutantStack();


}

LineManager::LineManager(LineManager const &src) {

	*this = src;
}

LineManager::~LineManager() {
}

LineManager				&LineManager::operator=(LineManager const &rhs) {

	this->line = rhs.line;
	this->stack = rhs.stack;

	return *this;
}


std::ostream	&operator<<(std::ostream &o, LineManager const &rhs) {

	o << rhs.getLine();
	return o;
}

/*--------------------------------------------------------*/
/*                        getter                          */
/*--------------------------------------------------------*/

std::string 	LineManager::getLine() const
{
	return this->line;
}

std::string 	LineManager::getNline()
{
	std::stringstream ss;
	std::string s;

	ss << LineManager::nline;
	s = ss.str();
	return s;
}

/*--------------------------------------------------------*/
/*                       parsing                          */
/*--------------------------------------------------------*/

void 	LineManager::parseLine(std::string str)
{
	t_instruct instr[] = {&LineManager::push, &LineManager::pop, &LineManager::mul, &LineManager::my_div, &LineManager::mod, &LineManager::print, &LineManager::my_exit, &LineManager::my_assert, &LineManager::dump, &LineManager::add, &LineManager::sub,};
	std::string instr_n[] = {"push", "pop", "mul", "div", "mod", "print", "my_exit", "assert", "dump", "add", "sub"};

	this->args = conversion::this->argslit(str, ' ');
	if (this->args.size() > 2 || this->args.size() == 0)
		throw SyntaxeException();
	if (this->args.size() == 1)
		this->args.push_back("");
	for(int i = 0; i < 11; i++)
	{
		if (this->args.front() == instr_n[i])
			(this->*instr[i])();
	}
}

IOperand	*

/*--------------------------------------------------------*/
/*               Instruction sans Argument                */
/*--------------------------------------------------------*/

void		LineManager::mul()
{
	IOperand *a;
	IOperand *b;

	if (this->stack.size() < 2)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	b = this->stack.pop();
	a *= b;
	this->stack.push(a);
}

void		LineManager::sub()
{
	IOperand *a;
	IOperand *b;

	if (this->stack.size() < 2)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	b = this->stack.pop();
	a -= b;
	this->stack.push(a);
}

void		LineManager::div()
{
	IOperand *a;
	IOperand *b;

	if (this->stack.size() < 2)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	b = this->stack.pop();
	a /= b;
	this->stack.push(a);
}

void		LineManager::mod()
{
	IOperand *a;
	IOperand *b;

	if (this->stack.size() < 2)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	b = this->stack.pop();
	a %= b;
	this->stack.push(a);
}

void		LineManager::add()
{
	IOperand *a;
	IOperand *b;

	if (this->stack.size() < 2)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	b = this->stack.pop();
	a += b;
	this->stack.push(a);
}

void		LineManager::dump()
{
	IOperand *a;
*
	if (this->stack.size() < 1)
		throw StackException();
	if (this->args.size > 1)
		throw SyntaxeException();
	a = this->stack.pop();
	std::cout << a.to_String() << std::endl;
}

/*--------------------------------------------------------*/
/*               Instruction sans Argument                */
/*--------------------------------------------------------*/

void		LineManager::push()
{
}
