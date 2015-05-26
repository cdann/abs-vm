#ifndef FILEPARSER_HPP
# define FILEPARSER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <list>

class FileParser {

public:
	FileParser();
	FileParser(char *file);
	FileParser(FileParser const &);
	virtual ~FileParser();
	void check();
	int			getLine(std::string& li);
	FileParser			&operator=(FileParser const &);

private:
	std::list<std::string> lines;

	//

};
std::ostream	&operator<<(std::ostream &o, FileParser const &rhs) ;


#endif
