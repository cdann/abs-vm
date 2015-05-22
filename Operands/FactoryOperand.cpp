#include "FactoryOperand.hpp"
#include <iostream>
#include "Operand.tpp"


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
	o << "Factory" << std::endl;
	return o;
}

IOperand *FactoryOperand::make(eOperandType op)
{

	t_ope instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32, &FactoryOperand::makeFloat, &FactoryOperand::makeDouble};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};

	for(int i = 0; i < 5; i++)
	{
		if (op == instr_n[i])
			return (this->*instr[i])();
	}
	return NULL;
}

IOperand *FactoryOperand::make(eOperandType op, std::string val)
{
	t_opestr instr[] = {&FactoryOperand::createInt8, &FactoryOperand::createInt16, &FactoryOperand::createInt32, &FactoryOperand::createFloat, &FactoryOperand::createDouble};

	eOperandType instr_n[] = {INT8, INT16, INT32, FLOAT, DOUBLE};
	for(int i = 0; i < 5; i++)
	{
		if (op == instr_n[i])
		{
			return (this->*instr[i])(val);
		}
	}
	return NULL;
}

IOperand *FactoryOperand::make(eOperandType op, double val)
{

	t_opedouble instr[] = {&FactoryOperand::makeInt8, &FactoryOperand::makeInt16, &FactoryOperand::makeInt32, &FactoryOperand::makeFloat, &FactoryOperand::makeDouble};
	eOperandType instr_n[] = { INT8, INT16, INT32, FLOAT, DOUBLE };

	for(int i = 0; i < 5; i++)
	{
		if (op == instr_n[i])
			return (this->*instr[i])(val);
	}
	return NULL;
}


/*--------------------------------------------------------*/
/*                           FLOAT                        */
/*--------------------------------------------------------*/

IOperand *FactoryOperand::makeFloat()
{
	return new Operand<float>();
}

IOperand *FactoryOperand::createFloat(std::string val)
{
	return new Operand<float>(val);
}

IOperand *FactoryOperand::makeFloat(double val)
{
	return new Operand<float>(val);
}


/*--------------------------------------------------------*/
/*                          DOUBLE                        */
/*--------------------------------------------------------*/

IOperand *FactoryOperand::makeDouble()
{
	return new Operand<double>();
}

IOperand *FactoryOperand::createDouble(std::string val)
{
	return new Operand<double>(val);
}

IOperand *FactoryOperand::makeDouble(double val)
{
	return new Operand<double>(val);
}


/*--------------------------------------------------------*/
/*                           INT16                        */
/*--------------------------------------------------------*/

IOperand *FactoryOperand::makeInt16()
{
	return new Operand<short>();
}

IOperand *FactoryOperand::createInt16(std::string val)
{
	return new Operand<short>(val);
}

IOperand *FactoryOperand::makeInt16(double val)
{
	return new Operand<short>(val);
}


/*--------------------------------------------------------*/
/*                           INT8                         */
/*--------------------------------------------------------*/

IOperand *FactoryOperand::makeInt8()
{
	return new Operand<char>();
}

IOperand *FactoryOperand::createInt8(std::string val)
{
	return new Operand<char>(val);
}

IOperand *FactoryOperand::makeInt8(double val)
{
	return new Operand<char>(val);
}


/*--------------------------------------------------------*/
/*                           INT32                        */
/*--------------------------------------------------------*/

IOperand *FactoryOperand::makeInt32()
{
	return new Operand<int>();
}

IOperand *FactoryOperand::createInt32(std::string val)
{
	return new Operand<int>(val);
}

IOperand *FactoryOperand::makeInt32(double val)
{
	return new Operand<int>(val);
}

