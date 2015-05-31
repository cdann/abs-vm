#ifndef TOOLBOX_H
#define TOOLBOX_H

# include "LineManager.hpp"
# include <list>

namespace ToolBox{
	double						toDouble(std::string str);
	std::list<std::string>	split(std::string str, char c);
	std::list<std::string>	split(std::string str, char *c);
	void						trim(std::string & str);
	bool						isdigit(std::string str, bool b);
	bool						isexpo(std::string str, std::string::iterator & it, bool & e);
	bool						isvirg(std::string str, std::string::iterator & it, bool & v, bool in);
	bool						issign(std::string str, std::string::iterator  it ,bool in);
	bool						isnumber(std::string::iterator  it);
	bool						isonlyspace(std::string str);
	size_t 						find(std::string s, char *ch, size_t f);
	template < typename T>
	std::string					toString(T x){
		std::stringstream ss;
		std::string s;

		ss << x;
		s = ss.str();
		return s;
	}
}

#endif
