#include "pugixml.hpp"

#include <iostream>

void R(pugi::xml_node n, int p = 0)
{
	for (const auto& c : n.children())
	{
		for(int i  = 0; i < p; i++)
		{
			std::cout << "\t";
		}
		std::cout << c.name() << std::endl;
		R(c, p+1);
	}
}

int main()
{
	// tag::code[]
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../../tests/testdata/testApp.gml");

	std::cout << result.description() << std::endl;

	R(doc);
	// end::code[]
}

// vim:et
