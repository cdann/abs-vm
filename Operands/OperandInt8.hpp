#ifndef INT8_H
# define INT8_H
# include "IOperand.hpp"

class OperandInt8 : public IOperand
{
	public:
		OperandInt8();
		OperandInt8(std::string value);
		OperandInt8(double value);
		~OperandInt8();
		OperandInt8(OperandInt8 const &src);
		OperandInt8& operator=(OperandInt8 const &rhs);


		IOperand const * operator+( IOperand const & rhs ) const; // Sum
		IOperand const * operator-( IOperand const & rhs ) const; // Difference
		IOperand const * operator*( IOperand const & rhs ) const; // Product
		IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		IOperand const * operator%( IOperand const & rhs ) const; // Modulo'

		std::string const & toString( void ) const; // String representation of the 	instance
		int getPrecision( void ) const; // Precision of the type of the instance
		eOperandType getType( void ) const; // Type of the instance



	private:
		int				precision;
		eOperandType	type;
		short			value;
		std::string		string;

		static short fromString(std::string str);
		static std::string fromValue(short val);


	//short
};

std::ostream		&operator<<(std::ostream &, OperandInt8 const &);


#endif
