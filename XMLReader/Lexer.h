#pragma once
#include <string>
#include <vector>

struct Token
{
	enum class Type
	{
		UNKNOWN,
		TAG,
		TEXT

	};

	Token(Type aType, const std::string& aText, int aStartPos) : m_type(aType), m_text(aText), m_startPos(aStartPos) {}

	Type m_type = Type::UNKNOWN;
	std::string m_text;
	int m_startPos = -1;
};

namespace Lexer
{
	void Lex(std::ifstream& aStream, std::vector<Token>& oTokens);
};

