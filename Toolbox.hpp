#ifndef TOOLBOX_H
#define TOOLBOX_H

# include "LineManager.hpp"

namespace ToolBox{
	double						toDouble(std::string str);
	std::list<std::string>	split(std::string str, char c);
	void						trim(std::string & str);
	bool						isdigit(std::string str, bool b);
	bool						isonlyspace(std::string str);

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
