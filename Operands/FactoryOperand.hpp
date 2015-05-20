#ifndef OPEFACT_H
# define OPEFACT_H
# include "IOperand.hpp"
# include "OperandInt8.hpp"
# include "OperandInt16.hpp"
# include "OperandInt32.hpp"
# include <map>


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
		//IOperand		*make(std::string str);
		static FactoryOperand	Factory;

	private:
		IOperand			*makeInt32();
		IOperand			*createInt32(std::string val);
		IOperand			*makeInt32(double val);

		IOperand			*makeInt16();
		IOperand			*createInt16(std::string val);
		IOperand			*makeInt16(double val);

		IOperand			*makeInt8();
		IOperand			*createInt8(std::string val);
		IOperand			*makeInt8(double val);


};

std::ostream	&operator<<(std::ostream &o, FactoryOperand const &rhs);

typedef IOperand* (FactoryOperand::*t_ope)();
typedef IOperand* (FactoryOperand::*t_opestr)(std::string);
typedef IOperand* (FactoryOperand::*t_opedouble)(double);


#endif
