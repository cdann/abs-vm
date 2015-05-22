#include "LineManager.hpp"
#include "AssertException.hpp"
#include "OperandException.hpp"
#include "StackException.hpp"
#include "SyntaxeException.hpp"
#include "FileParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		FileParser File(argv[1]);
	else if (argc == 0)
		FileParser File;
	else
		throw std::exception("usage : ./AbstractVM [file] \n");
	LineManager TheBoss;

	try{

		TheBoss.parseLine("push float(42.62)");
		TheBoss.parseLine("print");
		TheBoss.parseLine("push int8(2)");
		TheBoss.parseLine("add");
		TheBoss.parseLine("push int8(52)");
		TheBoss.parseLine("dump");
		TheBoss.parseLine("assert int8(82)");
	} catch (AssertException e)
	{
		std::cout << e.what();
	} catch (OperandException e)
	{
		std::cout << e.what();
	} catch (StackException e)
	{
		std::cout << e.what();
	} catch (SyntaxeException e)
	{
		std::cout << e.what();
	} catch (std::exception e)
	{
		std::cout << e.what();
	}

	return 0;
}
