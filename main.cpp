#include <iostream>
#include <vector>

#include "XMLReader.h"


int main(int argc, char** argv)
{
	rlx::XMLReader reader;
	int index = reader.CreateElement(-1);

    std::cout << "Hello World" << "\n";

    return 0;
}
