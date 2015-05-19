#ifndef INT32_H
# define INT32_H
# include "IOperand.hpp"

class OperandInt32 : public IOperand
{
	public:
		OperandInt32();
		~OperandInt32();
		OperandInt32(std::string value);
		OperandInt32(double value);

		int getPrecision( void ) const; // Precision of the type of the instance
		eOperandType getType( void ) const; // Type of the instance
		IOperand const * operator+( IOperand const & rhs ) const; // Sum
		IOperand const * operator-( IOperand const & rhs ) const; // Difference
		IOperand const * operator*( IOperand const & rhs ) const; // Product
		IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		IOperand const * operator%( IOperand const & rhs ) const; // Modulo
		std::string const & toString( void ) const; // String representation of the 	instance

	private:
		int precision;

	//char

};

#endif
