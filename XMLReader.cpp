#include "XMLReader.h"

rlx::XMLReader::~XMLReader()
{
	for (auto el : m_elements)
	{
		delete el;
	}
	m_elements.clear();
}

bool rlx::XMLReader::Read(std::filesystem::path aPath, XMLElement& oRoot)
{


	return true;
}
