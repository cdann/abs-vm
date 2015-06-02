#ifndef SYNTEXCEPT_H
# define SYNTEXCEPT_H

# include <stdexcept>
# include <list>
enum SYNT_ERR { ERR_INSTR, ERR_OPSYNT, ERR_OPMISS, ERR_OPOUT, ERR_DIGIT, ERR_VALUE, ERR_INSTRSYNT};


class SyntaxeException: public std::exception
{
	public:
		virtual const char* what() const throw();
		SyntaxeException() throw();
		SyntaxeException(SYNT_ERR) throw();
		SyntaxeException(SyntaxeException const & src) throw();
		SyntaxeException		&operator=(SyntaxeException const &src);
		static bool getverbose();
		static void setverbose();
		virtual ~SyntaxeException() throw();

	private:
		static bool			verbose;
		SYNT_ERR err;
		std::list<std::string> list;
		std::string		show_line(std::string line, std::string piece) const;

};

#endif
