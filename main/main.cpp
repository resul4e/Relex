#include <iostream>
#include <vector>

#include "XMLReader.h"


int main(int argc, char** argv)
{
	rlx::XMLReader reader;
	rlx::XMLElement index = reader.CreateElement(-1);

    std::cout << "Hello World" << "\n";

    return 0;
}
