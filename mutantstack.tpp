#ifndef MUTANT_H
# define MUTANT_H
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void) : std::stack<T>()
		{}

		template <typename C>
		MutantStack<T>(C &src) : std::stack<T>(src)
		{}



		~MutantStack<T>(void)
		{}

		MutantStack<T>&		operator=(const MutantStack<T> & op )
		{
			return (*this);
		}

		class iterrator
		{
			public:
				iterrator()
				{}

				iterrator(MutantStack<T>::iterrator const &src)
				{
					*this = src;
				}

				MutantStack<T>::iterrator	operator=(const MutantStack<T>::iterrator & op )
				{
					return *this;
				}

				~iterrator()
				{}

				T *ptr;

		};

	private:
		MutantStack<T>::iterrator begin;
		MutantStack<T>::iterrator end;
};

#endif
