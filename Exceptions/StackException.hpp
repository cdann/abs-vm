#ifndef STACKEXCEPT_H
# define STACKEXCEPT_H

# include <stdexcept>

enum STACK_ERR { OPER_ERR, POP_ERR};


class StackException: public std::exception
{
	public:
		virtual const char* what() const throw();
		StackException() throw();
		StackException(STACK_ERR) throw();
		StackException(StackException const & src) throw();
		StackException		&operator=(StackException const &src);
		virtual ~StackException() throw();

	private:
		STACK_ERR err;
};

#endif
