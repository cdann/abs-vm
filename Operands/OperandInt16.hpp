#ifndef INT16_H
# define INT16_H
# include "IOperand.hpp"

class OperandInt16 : public IOperand
{
	public:
		OperandInt16();
		OperandInt16(std::string value);
		OperandInt16(double value);
		~OperandInt16();
		OperandInt16(OperandInt16 const &src);
		OperandInt16& operator=(OperandInt16 const &rhs);


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

std::ostream		&operator<<(std::ostream &, OperandInt16 const &);


#endif
