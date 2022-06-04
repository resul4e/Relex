#include "XMLReader.h"
#include <fstream>

#include "Lexer.h"


rlx::XMLElement& rlx::XMLDocument::Root() const
{
	return m_reader->m_elements[m_root];
}

rlx::XMLReader::~XMLReader()
{
	m_internalElements.clear();
}

bool rlx::XMLReader::Read(std::filesystem::path aPath, XMLDocument& oDocument)
{
	std::ifstream stream(aPath.c_str());

	if(!stream.is_open())
	{
		return false;
	}

	oDocument.m_reader = this;

	std::vector<Token> tokens;
	Lexer::Lex(stream, tokens);

	if(tokens[0].m_text[1] == '?')
	{
		CreateElement(INVALID_ELEMENT_INDEX);
		tokens.erase(tokens.begin());
	}

	for(const auto& tok : tokens)
	{

		CreateElement(INVALID_ELEMENT_INDEX);
	}

	stream.close();

	return true;
}

rlx::XMLElement rlx::XMLReader::CreateElement(size_t aParent)
{
	const size_t index = m_internalElements.size();

	XMLElement_internal el{};
	el.m_parent = { this, aParent };

	if(aParent != INVALID_ELEMENT_INDEX)
	{
		m_internalElements[aParent].m_children.push_back({ this, index });
	}


	m_internalElements.push_back(el);
	return {this, index};
}

rlx::XMLElement rlx::XMLReader::CreateElements(std::ifstream& aStr)
{
	char rawLine[1024];
	aStr.getline(rawLine, 1024);
	

	return CreateElement(INVALID_ELEMENT_INDEX);
}
