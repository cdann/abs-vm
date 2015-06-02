#include "LineManager.hpp"
#include "FactoryOperand.hpp"
#include "SyntaxeException.hpp"
#include "StackException.hpp"
#include "AssertException.hpp"
#include "OperandException.hpp"
#include <list>
#include <vector>
#include "ToolBox.hpp"


//FactoryOperand	LineManager::Factor;
std::string				LineManager::line;
std::list<std::string>		LineManager::args;
int							LineManager::nline = 0;
bool						LineManager::isOn = true;
bool						LineManager::Parser = false;

/*--------------------------------------------------------*/
/*                       Canonique                        */
/*--------------------------------------------------------*/

LineManager::LineManager() {
	stack = new MutantStack<const IOperand*>();
	nline = 0;
	isOn = true;
	args.clear();
	line = "";
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
/*                      getter/setter                     */
/*--------------------------------------------------------*/

std::string 	LineManager::getLine()
{
	return LineManager::line;
}

std::list<std::string> 	LineManager::getArgs()
{
	return LineManager::args;
}

std::string 	LineManager::getNline()
{
	std::stringstream ss;
	std::string s;

	ss << LineManager::nline;
	s = ss.str();
	return s;
}

bool			LineManager::getOn()
{
	return LineManager::isOn;
}

void		LineManager::setParser()
{
//	std::cout << "blabla";
	LineManager::Parser = true;
}


/*--------------------------------------------------------*/
/*                       parsing                          */
/*--------------------------------------------------------*/

void 	LineManager::reformLine(std::string & str)
{
	size_t found1 = 0;
	size_t found2 = 0;
	std::string s;
	std::list<std::string> st;
	char car[] = {' ', '\t'};

	found1 = str.find('(');
	s = str;
	if (found1 != std::string::npos)
	{
		st = ToolBox::split(str.substr(0, found1), car);
	}
	else
		ToolBox::trim(str);
	//for(std::list<std::string>::iterator it = st.begin() ; it != st.end() ; it++ )
	//{
	//	//std::cout << "+" << *it << "|" << std::endl;
	//}
	found2 = str.find(')');
	if (found2 != std::string::npos && st.size() == 2)
	{
		s = str.substr(found1+1, found2 - found1 - 1);
		ToolBox::trim(s);
		str = st.front() + " " + st.back() + "(" + s + ")";
	}
	//else
	//{
	//	str = "";
	//	for(std::list<std::string>::iterator it = st.begin() ; it != st.end() ; it++ )
	//	{
	//		if (it != st.begin())
	//			str += " ";
	//		str += *it ;
	//	}
	//	str += " " + s.substr(found1, str.size());
	//}
	//type ( value )

	//std::cout<< ">>>>|" << str << "|" << std::endl ;

}

void 	LineManager::parseLine(std::string str, bool err)
{
	this->noPrint = err;
	this->line = str;
	t_instruct instr[] = {&LineManager::push, &LineManager::pop, &LineManager::mul, &LineManager::my_div, &LineManager::mod, &LineManager::print, &LineManager::my_exit, &LineManager::my_assert, &LineManager::dump, &LineManager::add, &LineManager::sub,};
	std::string instr_n[] = {"push", "pop", "mul", "div", "mod", "print", "exit", "assert", "dump", "add", "sub"};
	//std::cout << "plouf";
	LineManager::nline ++;
	//std::cout << "bim >> " << std::endl;
	if (LineManager::Parser == true)
		this->reformLine(str);
	this->args = ToolBox::split(str, ' ');
	//if (LineManager::Parser == true)
	//{
	//	for(std::list<std::string>::iterator it = this->args.begin() ; it != this->args.end() ; it++ )
	//	{
	//		ToolBox::trim(*it);
//
	//	}
	//		this->args.remove("");
	//	for(std::list<std::string>::iterator it = this->args.begin() ; it != this->args.end() ; it++ )
	//	{
	//		std::cout<< "|" << *it ;
	//	}
	//}
	//(this->args.front() != "push")? std::cout << "KO " : std::cout << "OK" << this->args.size();


	//	std::cout <<  << " // ";
	//std::cout << args.size() << std::endl;
	//std::cout << "{" <<this->args.back() << "}" << std::endl;
	if (this->args.size() > 2 || this->args.size() == 0)
	{
		throw SyntaxeException(ERR_INSTRSYNT);
	}
	//std::cout << "^^" << this->args.front() << "|" <<std::endl;

	for(int i = 0; i < 11; i++)
	{
		if (this->args.front() == instr_n[i])
		{
			(this->*instr[i])();
			return;
		}
	}

	throw SyntaxeException(ERR_INSTR);
}

IOperand	*LineManager::parseOperand()
{
	//Int8(N)

	std::string arg = this->args.back();
	this->args.pop_back();
	size_t found = 0;
	std::string part[2];

	found = arg.find('(');
	if (found != std::string::npos )
	{
		part[0] = arg.substr(0, found );
		//if (LineManager::Parser == true)
		//{
		//	ToolBox::trim(part[0]);
		//	std::cout<< "|" << part[0] <<"|";
		//}

		this->args.push_back(part[0]);
		if (arg[arg.size() - 1] != ')')
		{
			part[1] = arg.substr(found, arg.size() - found);
			this->args.push_back(part[1]);
			//std::cout << "plouf";
			throw SyntaxeException(ERR_VALUE);
		}
		part[1] = arg.substr(found + 1, arg.size() - found -2);
		this->args.push_back(part[1]);
	}
	else
	{
		//std::cout << "erreur!!" << line <<std::endl;
		throw SyntaxeException(ERR_OPMISS);
	}
	if (part[1].size() == 0)
		throw OperandException(VALUE_ERR);
	//std::cout << "#####"<< part[1] <<std::endl;
	IOperand	*ret = NULL;
	std::string instr[] = {"int8", "int16", "int32","float", "double"};
	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };

	for(int i = 0; i < 5; i++)
	{
		if (part[0] == instr[i])
			ret = FactoryOperand::Factory.make(instr_n[i], part[1]);
	}
	if (ret == NULL)
		throw SyntaxeException(ERR_VALUE);
	//ret = FactoryOperand::Factory.make(INT8, "4");
	return ret;
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
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
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
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
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
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
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
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
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
	{
		throw StackException(OPER_ERR);
	}
	if (this->args.size() > 1)
	{

		throw SyntaxeException(ERR_OPOUT);
	}

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
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
	if (!this->noPrint)
	{
		for (MutantStack<const IOperand*>::iterator it = this->stack->begin(); it != this->stack->end(); it++)
		{
			a = *it;
			std::cout << a->toString() << std::endl;
		}
	}
	//this->stack->pop();
}

void		LineManager::print()
{

	const IOperand *a;

	//std::cout <<"bammmm";
	if (this->stack->size() < 1)
		throw StackException(OPER_ERR);
	if (this->args.size() > 1)
	{
		throw SyntaxeException(ERR_OPOUT);
	}
	a = this->stack->top();
	double d = ToolBox::toDouble(a->toString());
	if (!this->noPrint)
		std::cout << static_cast<char>(d) << std::endl;
	//write(1, "!" , 1);
}

void		LineManager::my_exit()
{
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
	LineManager::isOn = false;
}

void		LineManager::pop()
{
	if (this->args.size() > 1)
		throw SyntaxeException(ERR_OPOUT);
	if (this->stack->size() < 1)
		throw StackException(POP_ERR);
	this->stack->pop();
}

/*--------------------------------------------------------*/
/*               Instruction sans Argument                */
/*--------------------------------------------------------*/

void		LineManager::push()
{
//	std::cout << "PLOPP";
	if (this->args.size() < 2)
		throw SyntaxeException(ERR_OPMISS);
	this->stack->push(parseOperand());
	//std::cout << "&&" << this->stack->size() << std::endl;
}


void		LineManager::my_assert()
{
	int i = 0;
	eOperandType type_tab[] = {INT8, INT16, INT32, FLOAT, DOUBLE};
	t_cast func[] = {&FactoryOperand::compareInt8, &FactoryOperand::compareInt16, &FactoryOperand::compareInt32, &FactoryOperand::compareFloat, &FactoryOperand::compareDouble};
	if (this->args.size() < 2)
		throw SyntaxeException(ERR_OPMISS);
	IOperand* tmp = parseOperand();
	IOperand* first = const_cast<IOperand*>(this->stack->top());

//std::cout << (first->getType() == tmp->getType()) << std::endl;
	while (i < 5)
	{
		if (type_tab[i] == first->getType() && (first->getType() != tmp->getType() || !(*func[i])(tmp, first)))
		{
			throw AssertException();
		}
		i++;
	}
}

