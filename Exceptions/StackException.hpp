#ifndef STACKEXCEPT_H
# define STACKEXCEPT_H

# include <stdexcept>

class StackException: public std::exception
{
	public:
		virtual const char* what() const throw();
		StackException() throw();
		StackException(StackException const & src) throw();
		StackException		&operator=(StackException const &src);
		virtual ~StackException() throw();
};

#endif
