#ifndef ASSERTEXCEPT_H
# define ASSERTEXCEPT_H

# include <stdexcept>



class AssertException: public std::exception
{
	public:
		virtual const char* what() const throw();
		AssertException() throw();
		AssertException(AssertException const & src) throw();
		AssertException		&operator=(AssertException const &src);
		virtual ~AssertException() throw();

};

#endif
