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
		void 				parseLine(std::string str);
		IOperand			*parseOperand();
		/*
		statics getter/setter
		 */
		static std::string 				getLine();
		static std::list<std::string> 	getArgs();
		static bool 					getOn();
		static void 					setParser();

	private:
		static int						nline;
		static bool						isOn;
		static std::list<std::string>	args;
		static std::string				line;

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





};

typedef void (LineManager::*t_instruct)();
typedef bool  (*t_cast)(IOperand *a, IOperand *b);
//typedef IOperand* (FactoryOperand::*t_opestr)(std::string);

std::ostream		&operator<<(std::ostream &, LineManager const &);

#endif
