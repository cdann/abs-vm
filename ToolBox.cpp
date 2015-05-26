#include <string>
#include <sstream>
#include <list>
#include "ToolBox.hpp"


double   ToolBox::toDouble(std::string str){
	double d;
	char * cstr = new char [str.length()+1];

	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	return d;
}

std::list<std::string> ToolBox::split(std::string str, char c)
{
	std::list<std::string>	ret;
	size_t							s = 0;
	size_t							found = 0;

	found = str.find(c, found);
	while (found != std::string::npos)
	{
		if (found != 0)
		{
			ret.push_back(str.substr(s, found - s));
			s = found + 1;
		}

		found = str.find(c + 1, found);
	}
	ret.push_back (str.substr(s, str.size() - s));
	return ret;
}

void ToolBox::trim(std::string & str)
{
	unsigned int end = 0;
	unsigned int start = 0;

	for (std::string::iterator it=str.begin(); it!=str.end(); it++)
	{
		if (*it == ' ')
			start++;
		else
			break;
	}
	for (std::string::reverse_iterator it=str.rbegin(); it!=str.rend(); it++)
	{
		if (*it == ' ')
			end++;
		else
			break;
	}
	str = str.substr(start, str.length() - end - start);
}

bool ToolBox::isdigit(std::string str, bool deci)
{
	bool point = false;
	bool in = false;

	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
	{
		if (in == false && (*it >= '0' && *it <= '9'))
			in = true;
		if (!((*it >= '0' && *it <= '9') || (*it == '.' && !point && deci == true)
			|| (*it == '-' && in == false) || (*it == '+' && in == false) || *it == ' '))
			return false;
		if (*it == ' ' && *(it - 1) != '-' && *(it - 1) != '+')
			return false;
		point = (*it == '.') ? true : point;
	}
	if (!in)
		return false;
	return true;
}

bool  ToolBox::isonlyspace(std::string str)
{
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
	{
		if ( *it != ' ')
			return false;
	}
	return true;
}

/*std::string ToolBox::between(std::string str, char before, char after)
{
	size_t	start = 0;
	size_t	end = 0;
	size_t	i = 0;

	for(std::string:iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == before && start == 0)
			start = i;
		if (*it == after && start != 0)
			end = i;
		i++;
	}
	return (str.substr(start, end - start));

}*/
