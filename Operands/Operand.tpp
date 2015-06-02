#ifndef OPER_H
# define OPER_H

# include "FactoryOperand.hpp"
# include "IOperand.hpp"
# include "ToolBox.hpp"
# include <sstream>
# include <iostream>
# include <string>
# include <limits>       // std::numeric_limits

#include "OperandException.hpp"
#include "SyntaxeException.hpp"

//class FactoryOperand;

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

		void  checkLimit(double d)
		{
			//std::cout << d << " " << static_cast<double>(std::numeric_limits<T>::min()) << " <-> " << static_cast<double>(std::numeric_limits<T>::max()) << std::endl;
			if (d < std::numeric_limits<T>::min())
			{
				throw OperandException(UNDER_ERR);
			}
			if (d > std::numeric_limits<T>::max())
				throw OperandException(OVER_ERR);
		}

		void  checkDigit(std::string d)
		{
			if (!ToolBox::isdigit(d, false))
			{
				//std::cout << "@@@@@@" << d << std::endl;
				throw SyntaxeException(ERR_DIGIT);
			}
		}

		bool  operator==(Operand<T> const & rhs ) const // Sum
		{
			if (this->value == rhs.value)
				return true;
			return false;
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
				//std::cout << "pop" << d << rhs.toString() << *this;
			if (this->value == 0)
			{
				//std::cout << "blaaaa";
				throw OperandException(DIV_ERR);
			}
			d = d / this->value;
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
			if (this->value == 0)
				throw OperandException(MOD_ERR);
			d = d % static_cast<int>(this->value);
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

		T	 getvalue( void ) const // Type of the instance
		{
			return this->value;
		}

	private:
		int const			precision;
		eOperandType const	type;
		T					value;
		std::string			string;


		T fromString(std::string str)
		{
			double	v;

			this->checkDigit(str);
			v = ToolBox::toDouble(str);
			this->checkLimit(v);
			return (static_cast<T>(v));
		}

		std::string fromValue(T val)
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
			this->value = static_cast<T>(val);
		}

		void	init(std::string val)
		{
			this->string = val;
			this->value = this->fromString(val);
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
void  Operand<float>::checkLimit(double d)
{
	//std::cout << d << " " << static_cast<double>(std::numeric_limits<float>::min()) << " <-> " << static_cast<double>(std::numeric_limits<float>::max()) << std::endl;
	if (d < 0)
		d *= -1;
	if (d < std::numeric_limits<float>::min())
		throw OperandException(UNDER_ERR);
	if (d > std::numeric_limits<float>::max())
		throw OperandException(OVER_ERR);
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

template <>
void  Operand<float>::checkDigit(std::string d)
{
	if (!ToolBox::isdigit(d, 1))
	{
//		std::cout << "PLAF";
		throw SyntaxeException(ERR_DIGIT);
	}
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
void  Operand<double>::checkLimit(double d)
{
	//std::cout << d << " " << static_cast<double>(std::numeric_limits<double>::min()) << " <-> " << static_cast<double>(std::numeric_limits<double>::max()) << std::endl;
	if (d < 0)
		d *= -1;
	if (d < std::numeric_limits<double>::min())
		throw OperandException(UNDER_ERR);
	if (d > std::numeric_limits<double>::max())
		throw OperandException(OVER_ERR);
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

template <>
void  Operand<double>::checkDigit(std::string d)
{
	if (!ToolBox::isdigit(d, 1))
		throw SyntaxeException(ERR_DIGIT);
}

#endif
