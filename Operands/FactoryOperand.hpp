#ifndef OPEFACT_H
# define OPEFACT_H
# include "IOperand.hpp"
# include "OperandInt8.hpp"
# include "OperandInt16.hpp"
# include "OperandInt32.hpp"
# include <map>

//enum Oper{INTx32, INT, FLOAT, DOUBLE, NOTFOUND};

class FactoryOperand
{
	public:
		FactoryOperand();
		FactoryOperand(FactoryOperand const &src);
		~FactoryOperand();
		FactoryOperand&	operator=(FactoryOperand const &rhs);
		IOperand		*make(eOperandType op, std::string val);
		IOperand		*make(eOperandType op, double val);
		IOperand		*make(eOperandType op);
		static FactoryOperand	Factory;

	private:
		OperandInt32			*makeInt32();
		OperandInt32			*makeInt32(std::string val);
		OperandInt32			*makeInt32(double val);

		OperandInt16			*makeInt16();
		OperandInt16			*makeInt16(std::string val);
		OperandInt16			*makeInt16(double val);

		OperandInt8				*makeInt8();
		OperandInt8				*makeInt8(std::string val);
		OperandInt8				*makeInt8(double val);


};

std::ostream	&operator<<(std::ostream &o, FactoryOperand const &rhs);

typedef IOperand* (FactoryOperand::*t_ope)();
typedef IOperand* (FactoryOperand::*t_opestr)(std::string);
typedef IOperand* (FactoryOperand::*t_opedouble)(double);


#endif
