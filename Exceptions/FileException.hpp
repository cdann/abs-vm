#ifndef FILEEXCEPT_H
# define FILEEXCEPT_H

# include <stdexcept>

enum FILE_ERR { EXIT_ERR, FILENAME_ERR};


class FileException: public std::exception
{
	public:
		virtual const char* what() const throw();
		FileException() throw();
		FileException(FILE_ERR err) throw();
		FileException(FileException const & src) throw();
		FileException		&operator=(FileException const &src);
		virtual ~FileException() throw();

	private:
		FILE_ERR	err;
};

#endif
