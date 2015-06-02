#ifndef FILEPARSER_HPP
# define FILEPARSER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <list>
#include "FileException.hpp"

class FileParser {

public:
	FileParser();
	FileParser(const char *file);
	FileParser(FileParser const &);
	virtual ~FileParser();
	void check();
	void 	checkline(std::string &line);
	int			getLine(std::string& li);
	FileParser			&operator=(FileParser const &);
	FILE_ERR			err;


private:
	std::list<std::string> lines;

	//

};
std::ostream	&operator<<(std::ostream &o, FileParser const &rhs) ;


#endif
