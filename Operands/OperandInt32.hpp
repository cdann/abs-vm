#ifndef INT32_H
# define INT32_H
# include "IOperand.hpp"

class OperandInt32 : public IOperand
{
	public:
		OperandInt32();
		OperandInt32(std::string value);
		OperandInt32(double value);
		~OperandInt32();
		OperandInt32(OperandInt32 const &src);
		OperandInt32& operator=(OperandInt32 const &rhs);


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

std::ostream		&operator<<(std::ostream &, OperandInt32 const &);


#endif
