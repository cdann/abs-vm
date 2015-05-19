#ifndef LINEMANAGER_HPP
# define LINEMANAGER_HPP

# include <iostream>
# include <sstream>
# include "MutantStack.tpp"
# include "IOperand.tpp"



class LineManager {

	public:
		LineManager();
		LineManager(LineManager const &);
		virtual ~LineManager();
		LineManager			&operator=(LineManager const &);

		void parseLine(std::string str);
		static std::string getNline();
		std::string 	getLine() const;

		//static LineManager	Manager;

	private:
		static int				nline;
		std::string				line;
		MutantStack<IOperand*>	*stack;
		std::vector<std::string> args;

		bool		searchInstruct(std::string);

		void		push(std::string &);
		void		pop(std::string &);
		void		mul(std::string &);
		void		my_div(std::string &);
		void		mod(std::string &);
		void		print(std::string &);
		void		my_exit(std::string &);
		void		my_assert(std::string &);
		void		dump(std::string &);
		void		add(std::string &);
		void		sub(std::string &);


};

typedef void (LineManager::*t_instruct)();

std::ostream		&operator<<(std::ostream &, LineManager const &);

#endif
