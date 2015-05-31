#include <string>
#include <sstream>
#include <list>
#include <vector>
#include "ToolBox.hpp"


double   ToolBox::toDouble(std::string str){
	double d;
	char * cstr = new char [str.length()+1];

	std::strcpy (cstr, str.c_str());
	d = std::strtod(cstr, &cstr);
	return d;
}


size_t ToolBox::find(std::string s, char *ch, size_t f)
{
	std::string tab(ch);
	size_t	min = s.size();
	size_t	found = 0;
	size_t		i = 0;
	while (i < tab.size())
	{
		found =s.find(tab[i], f);
		if (found != std::string::npos && found < min)
			min = found;
		++i;
	}
	if (min == s.size())
		return std::string::npos;
	std::cout << "min: "<<min << std::endl;
	return min;
}


std::list<std::string> ToolBox::split(std::string str, char c)
{
	std::list<std::string>	ret;
	//std::string				st;
	size_t							s = 0;
	size_t							found = 0;

	found = str.find(c, found);
	while (found != std::string::npos)
	{
		//std::cout << "&&&" << str.substr(found, str.size() - found) << "|" << std::endl;

		if (found != 0 && found != s)
		{
			//std::cout << str.size() << "tac >> "<< found << std::endl;
			ret.push_back(str.substr(s, found - s));
		}
		//else
		//	std::cout << "*|" << str.substr(0, found) << "|*" <<std::endl;
		s = found + 1;
			//std::cout << "("<<str<<")" <<std::endl;

		found = str.find(c, s);
		//while (found + 1 < str.size() && str[found + 1] == c)
		//	++found;
	}
	//std::cout << "&&&" << str.substr(s, str.size() - found) << "|" << std::endl;
	if (s != str.size())
	{
		//std::cout << "-|" << str.substr(s, str.size() - s) << "|-" <<std::endl;
		ret.push_back (str.substr(s, str.size() - s));
	}
	//std::cout << str << "$$$$"<< ret.size();
	return ret;
}

std::list<std::string> ToolBox::split(std::string str, char *c)
{
	std::list<std::string>	ret;
	//std::string				st;
	size_t							s = 0;
	size_t							found = 0;

	//found = str.find(c, found);
	found = find(str, c, found);
	while (found != std::string::npos)
	{
		//std::cout << "&&&" << str.substr(found, str.size() - found) << "|" << std::endl;

		if (found != 0 && found != s)
		{
			//std::cout << str.size() << "tac >> "<< found << std::endl;
			ret.push_back(str.substr(s, found - s));
		}
		//else
		//	std::cout << "*|" << str.substr(0, found) << "|*" <<std::endl;
		s = found + 1;
			std::cout << "("<<ret.back()<<")" <<std::endl;
		found = find(str, c, s);
		//found = str.find(c, s);
		//while (found + 1 < str.size() && str[found + 1] == c)
		//	++found;
	}
	//std::cout << ">>>" << str.substr(s, str.size() - found) << "|" << std::endl;
	if (s != str.size())
	{
		//std::cout << "-|" << str.substr(s, str.size() - s) << "|-" <<std::endl;
		ret.push_back (str.substr(s, str.size() - s));
	}
	//std::cout << str << "$$$$"<< ret.size();
	return ret;
}

void ToolBox::trim(std::string & str)
{
	unsigned int end = 0;
	unsigned int start = 0;
	//std::cout << "bam";

	for (std::string::iterator it=str.begin(); it!=str.end(); it++)
	{
		if (*it == ' ' || *it == '\t')
			start++;
		else
			break;
	}
	//std::cout << std::endl;
	for (std::string::reverse_iterator it=str.rbegin(); it!=str.rend(); it++)
	{
		if (*it == ' ' || *it == '\t')
			end++;
		else
			break;
	}
	str = str.substr(start, str.length() - end - start);
	//std::cout << "[[[[[" << str;
}

bool ToolBox::isexpo(std::string str, std::string::iterator & it, bool & e)
{
	if (*it == 'e' && it !=str.end() - 1 && (*(it + 1) == '+' || *(it + 1) == '-' ) &&  it + 1 !=str.end() - 1 && !e)
	{
		e = true;
		*it ++;
		return true;
	}
	return false;
}

bool ToolBox::isnumber(std::string::iterator  it)
{
	if (*it >= '0' && *it <= '9')
	{
		return true;
	}
	return false;
}

bool ToolBox::isvirg(std::string str, std::string::iterator & it, bool & v, bool in)
{
	if (*it == '.' && it != str.end() - 1 && in && !v)
	{
		v = true;
		return true;
	}
	return false;
}

bool ToolBox::issign(std::string str, std::string::iterator  it ,bool in)
{
	if (!in && (*it == '+' || *it == '-') && it != str.end() - 1 && ToolBox::isnumber(++it))
	{
		return true;
	}
	return false;
}

bool ToolBox::isdigit(std::string str, bool deci)
{
	bool point = false;
	bool expo = false;
	bool in = false;

	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
	{
		//std::cout << str.size() ;
		if (in == false && isnumber(it))
		{
			in = true;
		}
		if (!(isexpo(str, it, expo) || (isvirg(str, it, point, in) && deci) || issign(str, it, in) || isnumber(it)))
		{
			//std::cout << "KROKIEN" << *it  <<"|"<< std::endl;
			return false;
		}
		//if (!((*it >= '0' && *it <= '9') || (*it == '.' && !point && deci == true && it!=str.end() - 1)
		//	|| (*it == '-' && in == false) || (*it == '+' && in == false) ))
		//	return false;
		//point = (*it == '.') ? true : point;
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
