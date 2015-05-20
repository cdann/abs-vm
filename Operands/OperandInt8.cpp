#include "OperandInt8.hpp"
#include "FactoryOperand.hpp"
#include "OperandException.hpp"
#include <iostream>
#include <string>
#include <sstream>

/*--------------------------------------------------------*/
/*                       Canonique                        */
/*--------------------------------------------------------*/

OperandInt8::~OperandInt8() {}

OperandInt8::OperandInt8() : precision(8), type(INT8) {}

OperandInt8::OperandInt8(std::string val) : precision(8), type(INT8) {
	string = val;
	std::cout << "BOU<";
	value = fromString(val);
	std::cout << "RAA<";
}

OperandInt8::OperandInt8(double val) : precision(8), type(INT8) {
	std::stringstream ss;

	ss << val;
	string = ss.str();
	value = fromString(string);
}

OperandInt8::OperandInt8(OperandInt8 const &src)  {
	*this = src;
}

OperandInt8				&OperandInt8::operator=(OperandInt8 const &rhs)
{
	this->precision = rhs.precision;
	this->type = rhs.type;
	this->value = rhs.value;
	this->string = rhs.string;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, OperandInt8 const &rhs) {

	o << "INTx8 =>" << rhs.toString() << std::endl;
	return o;
}


/*--------------------------------------------------------*/
/*                      Conversions                       */
/*--------------------------------------------------------*/

short			OperandInt8::fromString(std::string str)
{
	double	v;
	char * cstr = new char [str.length()+1];

	std::strcpy (cstr, str.c_str());
	v = std::strtod(cstr, &cstr);
	return (static_cast<short>(v));
}

std::string		OperandInt8::fromValue(short val)
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

std::string const & OperandInt8::toString( void ) const // String representation of the 	instance
{
	return this->string;
}

int OperandInt8::getPrecision( void ) const // Precision of the type of the instance
{
	return this->precision;
}

eOperandType OperandInt8::getType( void ) const // Type of the instance
{
	return this->type;
}

/*--------------------------------------------------------*/
/*                       Operator                         */
/*--------------------------------------------------------*/

IOperand const * OperandInt8::operator+( IOperand const & rhs ) const // Sum
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


IOperand const * OperandInt8::operator-( IOperand const & rhs ) const // Sum
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

IOperand const * OperandInt8::operator*( IOperand const & rhs ) const // Sum
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

IOperand const * OperandInt8::operator/( IOperand const & rhs ) const // Sum
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

IOperand const * OperandInt8::operator%( IOperand const & rhs ) const // Sum
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

