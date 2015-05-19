#include "OperandInt16.hpp"
#include "FactoryOperand.hpp"
#include "OperandException.hpp"
#include <iostream>
#include <string>
#include <sstream>

/*--------------------------------------------------------*/
/*                       Canonique                        */
/*--------------------------------------------------------*/

OperandInt16::~OperandInt16() {}

OperandInt16::OperandInt16() : precision(16), type(INT16) {}

OperandInt16::OperandInt16(std::string val) : precision(16), type(INT16) {
	string = val;
	value = fromString(val);
}

OperandInt16::OperandInt16(double val) : precision(16), type(INT16) {
	std::stringstream ss;

	ss << val;
	string = ss.str();
	value = fromString(string);
}

OperandInt16::OperandInt16(OperandInt16 const &src)  {
	*this = src;
}

OperandInt16				&OperandInt16::operator=(OperandInt16 const &rhs)
{
	this->precision = rhs.precision;
	this->type = rhs.type;
	this->value = rhs.value;
	this->string = rhs.string;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, OperandInt16 const &rhs) {

	o << "INTx16 =>" << rhs.toString() << std::endl;
	return o;
}


/*--------------------------------------------------------*/
/*                      Conversions                       */
/*--------------------------------------------------------*/

short			OperandInt16::fromString(std::string str)
{
	double	v;
	char * cstr = new char [str.length()+1];

	std::strcpy (cstr, str.c_str());
	v = std::strtod(cstr, &cstr);
	delete cstr;
	return (static_cast<short>(v));
}

std::string		OperandInt16::fromValue(short val)
{
	std::stringstream ss;
	std::string s;

	ss << val;
	s = ss.str();
	return s;
}

/*--------------------------------------------------------*/
/*                        Getter                          */
/*--------------------------------------------------------*/

std::string const & OperandInt16::toString( void ) const // String representation of the 	instance
{
	return this->string;
}

int OperandInt16::getPrecision( void ) const // Precision of the type of the instance
{
	return this->precision;
}

eOperandType OperandInt16::getType( void ) const // Type of the instance
{
	return this->type;
}

/*--------------------------------------------------------*/
/*                       Operator                         */
/*--------------------------------------------------------*/

IOperand const * OperandInt16::operator+( IOperand const & rhs ) const // Sum
{
	double	d;
	eOperandType t;
	std::string str;
	char * cstr;
	IOperand *ret;

	str = rhs.toString();
	cstr = new char [str.length()+1];
	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	delete cstr;

	d += this->value;
	t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
	ret = FactoryOperand::Factory.make(t, d);
	return ret;
}


IOperand const * OperandInt16::operator-( IOperand const & rhs ) const // Sum
{
	double	d;
	eOperandType t;
	std::string str;
	char * cstr;
	IOperand *ret;

	str = rhs.toString();
	cstr = new char [str.length()+1];
	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	delete cstr;

	d -= this->value;
	t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
	ret = FactoryOperand::Factory.make(t, d);
	return ret;
}

IOperand const * OperandInt16::operator*( IOperand const & rhs ) const // Sum
{
	double	d;
	eOperandType t;
	std::string str;
	char * cstr;
	IOperand *ret;

	str = rhs.toString();
	cstr = new char [str.length()+1];
	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	delete cstr;

	d *= this->value;
	t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
	ret = FactoryOperand::Factory.make(t, d);
	return ret;
}

IOperand const * OperandInt16::operator/( IOperand const & rhs ) const // Sum
{
	double	d;
	eOperandType t;
	std::string str;
	char * cstr;
	IOperand *ret;

	str = rhs.toString();
	cstr = new char [str.length()+1];
	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	delete cstr;

	if (d == 0)
		throw OperandException(DIV_ERR);
	d = this->value / d ;
	t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
	ret = FactoryOperand::Factory.make(t, d);
	return ret;
}

IOperand const * OperandInt16::operator%( IOperand const & rhs ) const // Sum
{
	int	d;
	eOperandType t;
	IOperand *ret;


	d = atoi(rhs.toString().c_str());
	//d = std::strtod(cstr, &cstr);
	if (d == 0)
		throw OperandException(MOD_ERR);
	d = this->value % d;
	t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
	ret = FactoryOperand::Factory.make(t, d);
	return ret;
}

