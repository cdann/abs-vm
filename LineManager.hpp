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
		std::string 		getLine() const;

		//static LineManager	Manager;

	private:
		static int				nline;
		static bool				isOn;

		std::string				line;
		MutantStack<const IOperand*>	*stack;
		std::list<std::string> args;

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
//typedef IOperand* (FactoryOperand::*t_opestr)(std::string);

std::ostream		&operator<<(std::ostream &, LineManager const &);

#endif
