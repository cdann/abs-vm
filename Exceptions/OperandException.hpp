#ifndef OPEXCEPT_H
# define OPEXCEPT_H

# include <stdexcept>

enum OP_ERR { MOD_ERR, DIV_ERR, OVER_ERR, UNDER_ERR};


class OperandException: public std::exception
{
	public:
		virtual const char* what() const throw();
		OperandException() throw();
		OperandException(OP_ERR err) throw();
		OperandException(OperandException const & src) throw();
		OperandException		&operator=(OperandException const &src);
		virtual ~OperandException() throw();

	private:
		OP_ERR	err;
};

#endif
