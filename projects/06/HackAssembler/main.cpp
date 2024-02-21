#include "HackAssembler.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong argument count\n";
		return -1;
	}

	HackAssembler hackAssembler(av[1]);

	hackAssembler.run();
}
