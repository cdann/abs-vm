#ifndef SYNTEXCEPT_H
# define SYNTEXCEPT_H

# include <stdexcept>



class SyntaxeException: public std::exception
{
	public:
		virtual const char* what() const throw();
		SyntaxeException() throw();
		SyntaxeException(SyntaxeException const & src) throw();
		SyntaxeException		&operator=(SyntaxeException const &src);
		virtual ~SyntaxeException() throw();

};

#endif
