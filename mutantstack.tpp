#ifndef MUTANT_H
# define MUTANT_H
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack<T>(void) : std::stack<T>()
		{}

		MutantStack<T>(MutantStack<T> &src) : std::stack<T>(src)
		{
			*this = src;
		}

		~MutantStack<T>(void)
		{}

		MutantStack<T>&		operator=(const MutantStack<T> & op )
		{
			std::stack<T>::operator=(op);
			return (*this);
		}

		iterator begin(){
			return this->c.begin();
		}

		iterator end(){
			return this->c.end();
		}
};

#endif
