#include "LineManager.hpp"
#include "FactoryOperand.hpp"
#include "SyntaxeException.hpp"
#include "StackException.hpp"
#include <list>
#include "ToolBox.hpp"

//LineManager	LineManager::Manager;
int				LineManager::nline = 0;
bool			LineManager::isOn = true;
/*--------------------------------------------------------*/
/*                       Canonique                        */
/*--------------------------------------------------------*/

LineManager::LineManager() {
	stack = new MutantStack<const IOperand*>();


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

		//std::cout << "plouf";
	this->args = ToolBox::split(str, ' ');
		std::cout << str << std::endl;
	for(std::list<std::string>::iterator it = this->args.begin() ; it != this->args.end() ; it++ )
		std::cout << *it << " // ";
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

IOperand	*LineManager::parseOperand()
{
	//Int8(N)
	this->args.pop_front();
	std::string arg = this->args.front();
	size_t found = 0;
	std::string part[2];
	found = arg.find('(');

	eOperandType type;
	//IOperand	*ret;

	if (arg[arg.size() - 1] == ')' && found != std::string::npos)
	{
		part[0] = arg.substr(0, found );
		part[1] = arg.substr(found + 1, arg.size() - found -2);
	}

	std::string instr[] = {"Int8", "Int16", "Int32","Float", "Double"};
	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };
	for(int i = 0; i < 5; i++)
	{
		if (part[0] == instr[i])
			type = instr_n[i];
	}
	//ret = FactoryOperand::Factory.make(INT8, "4");
	return (FactoryOperand::Factory.make(type, "4"));
}

/*--------------------------------------------------------*/
/*               Instruction sans Argument                */
/*--------------------------------------------------------*/

void		LineManager::mul()
{
	const IOperand *a;
	const IOperand *b;
	const IOperand *c;

	if (this->stack->size() < 2)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	b = this->stack->top();
	this->stack->pop();
	c = *a * *b;
	this->stack->push(c);
}

void		LineManager::sub()
{
	const IOperand *a;
	const IOperand *b;
	const IOperand *c;

	if (this->stack->size() < 2)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	b = this->stack->top();
	this->stack->pop();
	c = *a - *b;
	this->stack->push(c);
}

void		LineManager::my_div()
{
	const IOperand *a;
	const IOperand *b;
	const IOperand *c;

	if (this->stack->size() < 2)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	b = this->stack->top();
	this->stack->pop();
	c = *a / *b;
	this->stack->push(c);
}

void		LineManager::mod()
{
	const IOperand *a;
	const IOperand *b;
	const IOperand *c;

	if (this->stack->size() < 2)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	b = this->stack->top();
	this->stack->pop();
	c = *a % *b;
	a = c;
	this->stack->push(c);
}

void		LineManager::add()
{
	const IOperand *a;
	const IOperand *b;
	const IOperand *c;

	if (this->stack->size() < 2)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	b = this->stack->top();
	this->stack->pop();
	c = *a + *b;
	this->stack->push(c);
}

void		LineManager::dump()
{
	const IOperand *a;

	if (this->stack->size() < 1)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	std::cout << a->toString() << std::endl;
}

void		LineManager::print()
{
	const IOperand *a;

	if (this->stack->size() < 1)
		throw StackException();
	if (this->args.size() > 1)
		throw SyntaxeException();
	a = this->stack->top();
	this->stack->pop();
	std::cout << a->toString() << std::endl;
}

void		LineManager::my_exit()
{
	LineManager::isOn = false;
}

/*--------------------------------------------------------*/
/*               Instruction sans Argument                */
/*--------------------------------------------------------*/

void		LineManager::push()
{
	std::cout << "#";
	parseOperand();
}

void		LineManager::pop()
{
	parseOperand();
}

void		LineManager::my_assert()
{
	parseOperand();
}
