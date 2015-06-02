#ifndef LINEMANAGER_HPP
# define LINEMANAGER_HPP

# include <iostream>
# include <sstream>
# include "MutantStack.tpp"
# include "IOperand.hpp"
# include <list>
# include <string>

class LineManager {

	public:
		static std::string	getNline();

		LineManager();
		LineManager(LineManager const &);
		virtual ~LineManager();

		LineManager			&operator=(LineManager const &);
		void 				parseLine(std::string str, bool b);
		IOperand			*parseOperand();
		/*
		statics getter/setter
		 */
		static std::string 				getLine();
		static std::list<std::string> 	getArgs();
		static bool 					getOn();
		static void 					setParser();

	private:
		static int						nline;//nombre de ligne
		static bool						isOn;//continue ou non
		static bool						Parser;//option -p
		static std::list<std::string>	args;//les differentes parties de la ligne
		static std::string				line;//la ligne

		bool							noPrint;
		MutantStack<const IOperand*>	*stack;

		bool		searchInstruct(std::string);
		void		push();
		void		pop();
		void		mul();
		void		my_div();
		void		mod();
		void		print();
		void		my_exit();
		void		my_assert();
		void		dump();
		void		add();
		void		sub();

		void 		reformLine(std::string & str);

};

typedef void (LineManager::*t_instruct)();
typedef bool  (*t_cast)(IOperand *a, IOperand *b);
//typedef IOperand* (FactoryOperand::*t_opestr)(std::string);

std::ostream		&operator<<(std::ostream &, LineManager const &);

#endif
