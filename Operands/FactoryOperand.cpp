#include "FactoryOperand.hpp"
#include <iostream>
# include "OperandInt8.hpp"
# include "OperandInt16.hpp"
# include "OperandInt32.hpp"

FactoryOperand	FactoryOperand::Factory;

FactoryOperand::FactoryOperand() {
}

FactoryOperand::FactoryOperand(FactoryOperand const &src) {
	*this = src;
}

FactoryOperand::~FactoryOperand() {
}

FactoryOperand				&FactoryOperand::operator=(FactoryOperand const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}


std::ostream	&operator<<(std::ostream &o, FactoryOperand const &rhs) {
	static_cast<void>(rhs);
	o << "plop" << std::endl;
	return o;
}
IOperand *FactoryOperand::makeInt16()
{
	return new OperandInt16();
}

IOperand *FactoryOperand::createInt16(std::string val)
{
	return new OperandInt16(val);
}
IOperand *FactoryOperand::makeInt16(double val)
{
	return new OperandInt16(val);
}

IOperand *FactoryOperand::makeInt8()
{
	return new OperandInt8();
}

IOperand *FactoryOperand::createInt8(std::string val)
{
	std::cout << "rfeu9ho" << std::endl;
	return new OperandInt8(val);
}
IOperand *FactoryOperand::makeInt8(double val)
{
	return new OperandInt8(val);
}

IOperand *FactoryOperand::makeInt32()
{
	return new OperandInt32();
}

IOperand *FactoryOperand::createInt32(std::string val)
{
	return new OperandInt32(val);
}
IOperand *FactoryOperand::makeInt32(double val)
{
	return new OperandInt32(val);
}

IOperand *FactoryOperand::make(eOperandType op)
{
std::cout << "PEK";

	//t_ope instr[] = {&FactoryOperand::createInt8, &FactoryOperand::createInt16, &FactoryOperand::createInt32/*, &FactoryOperand::createFloat, &FactoryOperand::createDouble*/};
	t_ope instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};

	for(int i = 0; i < 3; i++)
	{
		if (op == instr_n[i])
			return (this->*instr[i])();
	}
	return NULL;
}

IOperand *FactoryOperand::make(eOperandType op, std::string val)
{
	t_opestr instr[] = {&FactoryOperand::createInt8, &FactoryOperand::createInt16, &FactoryOperand::createInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};
	for(int i = 0; i < 3; i++)
	{
std::cout << op << "LOL" << instr_n[i];
		if (op == instr_n[i])
			return (this->*instr[i])(val);
	}
	return NULL;
}

IOperand *FactoryOperand::make(eOperandType op, double val)
{
std::cout << "PUK";

	t_opedouble instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};
	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };

	for(int i = 0; i < 3; i++)
	{
		if (op == instr_n[i])
			return (this->*instr[i])(val);
	}
	return NULL;
}

//IOperand *FactoryOperand::make(std::string)
//{
//	t_opedouble instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};
//	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };
//
//	for(int i = 0; i < 3; i++)
//	{
//		if (op == instr_n[i])
//			return (this->*instr[i])(val);
//	}
//	return NULL;
//}
