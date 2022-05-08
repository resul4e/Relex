#include "XMLReader.h"
#include <fstream>

#include "Lexer.h"

rlx::XMLReader::~XMLReader()
{
	m_elements.clear();
}

bool rlx::XMLReader::Read(std::filesystem::path aPath, XMLElement& oRoot)
{
	std::ifstream stream(aPath.c_str());

	if(!stream.is_open())
	{
		return false;
	}

	std::vector<Token> tokens;
	Lexer::Lex(stream, tokens);

	return true;
}

rlx::XMLElement rlx::XMLReader::CreateElement(int aParent)
{
	const int index = m_elements.size();

	XMLElement_internal el{};
	el.m_parent = { this, aParent };

	if(aParent != -1)
	{
		m_elements[aParent].m_children.push_back({ this, index });
	}


	m_elements.push_back(el);
	return {this, index};
}

rlx::XMLElement rlx::XMLReader::CreateElements(std::ifstream& aStr)
{
	char rawLine[1024];
	aStr.getline(rawLine, 1024);
	

	return CreateElement(-1);
}
