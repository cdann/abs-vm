#include "FactoryOperand.hpp"
#include <iostream>

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
OperandInt16 *FactoryOperand::makeInt16()
{
	return new OperandInt16();
}

OperandInt16 *FactoryOperand::makeInt16(std::string val)
{
	return new OperandInt16(val);
}
OperandInt16 *FactoryOperand::makeInt16(double val)
{
	return new OperandInt16(val);
}

OperandInt8 *FactoryOperand::makeInt8()
{
	return new OperandInt8();
}

OperandInt8 *FactoryOperand::makeInt8(std::string val)
{
	return new OperandInt8(val);
}
OperandInt8 *FactoryOperand::makeInt8(double val)
{
	return new OperandInt8(val);
}

OperandInt32 *FactoryOperand::makeInt32()
{
	return new OperandInt32();
}

OperandInt32 *FactoryOperand::makeInt32(std::string val)
{
	return new OperandInt32(val);
}
OperandInt32 *FactoryOperand::makeInt32(double val)
{
	return new OperandInt32(val);
}

IOperand *FactoryOperand::make(eOperandType op)
{
	//t_ope instr[] = {&FactoryOperand::createInt8, &FactoryOperand::createInt16, &FactoryOperand::createInt32, &FactoryOperand::createFloat, &FactoryOperand::createDouble};
	t_ope instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};

	switch(op)
	{
		case(INT32):
			return this->makeInt32();
		break;
		case(INT16):
			return this->makeInt16();
		break;
		case(INT8):
			return this->makeInt8();
		break;
		case(FLOAT):
			return this->makeInt8();
		break;
		case(DOUBLE):
			return this->makeInt8();
		break;
	}
}

IOperand *FactoryOperand::make(eOperandType op, std::string val)
{
	t_opestr instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};

	switch(op)
	{
		case(INT32):
			return this->makeInt32(val);
		break;
		case(INT16):
			return this->makeInt16(val);
		break;
		case(INT8):
			return this->makeInt8(val);
		break;
		case(FLOAT):
			return this->makeInt8(val);
		break;
		case(DOUBLE):
			return this->makeInt8(val);
		break;
	}
}

IOperand *FactoryOperand::make(eOperandType op, double val)
{
	t_opedouble instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32,/* &FactoryOperand::makeFloat, &FactoryOperand::makeDouble*/};

	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };

	switch(op)
	{
		case(INT32):
			return this->makeInt32(val);
		break;
		case(INT16):
			return this->makeInt16(val);
		break;
		case(INT8):
			return this->makeInt8(val);
		break;
		case(FLOAT):
			return this->makeInt8(val);
		break;
		case(DOUBLE):
			return this->makeInt8(val);
		break;
	}
}

