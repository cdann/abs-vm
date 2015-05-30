#ifndef SYNTEXCEPT_H
# define SYNTEXCEPT_H

# include <stdexcept>

enum SYNT_ERR { ERR_INSTR, ERR_OPSYNT, ERR_OPMISS, ERR_OPOUT, ERR_DIGIT, ERR_SIMPLE, ERR_VALUE};


class SyntaxeException: public std::exception
{
	public:
		virtual const char* what() const throw();
		SyntaxeException() throw();
		SyntaxeException(SYNT_ERR) throw();
		SyntaxeException(SyntaxeException const & src) throw();
		SyntaxeException		&operator=(SyntaxeException const &src);
		virtual ~SyntaxeException() throw();

	private:
		static bool			verbose;
		SYNT_ERR err;
		static std::string		show_line(std::string line, std::string piece);

};

#endif
