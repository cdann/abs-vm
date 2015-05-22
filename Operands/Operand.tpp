#ifndef OPER_H
# define OPER_H

# include "FactoryOperand.hpp"
# include "IOperand.hpp"
# include "ToolBox.hpp"
# include <sstream>
# include <iostream>
# include <string>

#include "OperandException.hpp"

template <typename T>
class Operand : public IOperand
{
	public:
		Operand<T>() {}
		Operand<T>(std::string value);
		Operand<T>(double value);

		~Operand<T>()
		{}

		Operand<T>(Operand<T> const &src)
		{
				*this = src;
		}

		Operand<T>& operator=(Operand<T> const &rhs)
		{
			this->precision = rhs.precision;
			this->type = rhs.type;
			this->value = rhs.value;
			this->string = rhs.string;
			return *this;
		}


		IOperand const * operator+( IOperand const & rhs ) const // Sum
		{
			double	d;
			eOperandType t;
			IOperand *ret;

			d = ToolBox::toDouble(rhs.toString());
			d += this->value;
			t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
			ret = FactoryOperand::Factory.make(t, d);
			return ret;
		}


		IOperand const * operator-( IOperand const & rhs ) const // Difference
		{
			double	d;
			eOperandType t;
			IOperand *ret;

			d = ToolBox::toDouble(rhs.toString());
			d -= this->value;
			t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
			ret = FactoryOperand::Factory.make(t, d);
			return ret;
		}

		IOperand const * operator*( IOperand const & rhs ) const // Product
		{
			double	d;
			eOperandType t;
			IOperand *ret;

			d = ToolBox::toDouble(rhs.toString());
			d *= this->value;
			t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
			ret = FactoryOperand::Factory.make(t, d);
			return ret;
		}

		IOperand const * operator/( IOperand const & rhs ) const // Quotient
		{
			double	d;
			eOperandType t;
			IOperand *ret;

			d = ToolBox::toDouble(rhs.toString());
			if (d == 0)
				throw OperandException(DIV_ERR);
			d = this->value/ d;
			t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
			ret = FactoryOperand::Factory.make(t, d);
			return ret;
		}

		IOperand const * operator%( IOperand const & rhs ) const // Modulo'
		{
			int	d;
			eOperandType t;
			IOperand *ret;

			d = atoi(rhs.toString().c_str());
			if (d == 0)
				throw OperandException(MOD_ERR);
			d = static_cast<int>(this->value) % d;
			t = (rhs.getType() > this->type) ? rhs.getType() : this->type;
			ret = FactoryOperand::Factory.make(t, d);
			return ret;
		}

		std::string const & toString( void ) const // String representation of the 	instance
		{
			return  this->string;
		}

		int getPrecision( void ) const // Precision of the type of the instance
		{
			return this->precision;
		}

		eOperandType getType( void ) const // Type of the instance
		{
			return this->type;
		}

	private:
		int const			precision;
		eOperandType const	type;
		T					value;
		std::string			string;


		static T fromString(std::string str)
		{
			double	v;

			v = ToolBox::toDouble(str);
			return (static_cast<T>(v));
		}

		static std::string fromValue(T val)
		{
			std::stringstream ss;
			std::string s;

			ss << val;
			s = ss.str();
			return s;
		}

		void	init(double val)
		{
			std::stringstream ss;

			ss << val;
			this->string = ss.str();
			this->value = fromString(string);
		}

		void	init(std::string val)
		{
			this->string = val;
			this->value = fromString(val);
		}

};



/*--------------------------------------------------------*/
/*                           INT8                         */
/*--------------------------------------------------------*/

template <>
Operand<char>::Operand() : precision(8), type(INT8) {}

template <>
Operand<char>::Operand(double val) : precision(8), type(INT8)
{
	this->init(val);
}

template <>
Operand<char>::Operand(std::string val) : precision(8), type(INT8)
{
	this->init(val);
}

std::ostream		&operator<<(std::ostream &o, Operand<char> const &rhs)
{
	o << "INTx8 =>" << rhs.toString() << std::endl;
	return o;
}




/*--------------------------------------------------------*/
/*                           INT16                        */
/*--------------------------------------------------------*/

template <>
Operand<short>::Operand() : precision(16), type(INT16) {}

template <>
Operand<short>::Operand(double val) : precision(16), type(INT16)
{
	this->init(val);
}

template <>
Operand<short>::Operand(std::string val) : precision(16), type(INT16)
{
	this->init(val);
}

std::ostream		&operator<<(std::ostream &o, Operand<short> const &rhs)
{
	o << "INTx16 =>" << rhs.toString() << std::endl;
	return o;
}



/*--------------------------------------------------------*/
/*                           INT32                        */
/*--------------------------------------------------------*/

template <>
Operand<int>::Operand() : precision(32), type(INT32) {}

template <>
Operand<int>::Operand(double val) : precision(32), type(INT32)
{
	this->init(val);
}

template <>
Operand<int>::Operand(std::string val) : precision(32), type(INT32)
{
	this->init(val);
}

std::ostream		&operator<<(std::ostream &o, Operand<int> const &rhs)
{
	o << "INTx32 =>" << rhs.toString() << std::endl;
	return o;
}



/*--------------------------------------------------------*/
/*                          FLOAT                         */
/*--------------------------------------------------------*/



template <>
Operand<float>::Operand() : precision(32), type(FLOAT) {

}

template <>
Operand<float>::Operand(double val) : precision(32), type(FLOAT)
{
	this->init(val);
}

template <>
Operand<float>::Operand(std::string val) : precision(32), type(FLOAT)
{
	this->init(val);
}

std::ostream		&operator<<(std::ostream &o, Operand<float> const &rhs)
{
	o << "FLOAT =>" << rhs.toString() << std::endl;
	return o;
}



/*--------------------------------------------------------*/
/*                          DOUBLE                        */
/*--------------------------------------------------------*/



template <>
Operand<double>::Operand() : precision(64), type(DOUBLE) {

}

template <>
Operand<double>::Operand(double val) : precision(64), type(DOUBLE)
{
	this->init(val);
}

template <>
Operand<double>::Operand(std::string val) : precision(64), type(DOUBLE)
{
	this->init(val);
}

std::ostream		&operator<<(std::ostream &o, Operand<double> const &rhs)
{
	o << "DOUBLE =>" << rhs.toString() << std::endl;
	return o;
}


#endif
