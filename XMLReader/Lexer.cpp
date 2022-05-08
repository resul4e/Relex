#include "Lexer.h"
#include <fstream>
#include <sstream>

void Lexer::Lex(std::ifstream& aStream, std::vector<Token>& oTokens)
{
	int currentPos = 0;
	while(!aStream.eof())
	{
		int tokenStartPos = currentPos;
		int nextChar = aStream.get();

		if (std::isspace(nextChar))
		{
			currentPos++;
		}
		else if (nextChar == '<')
		{
			currentPos++;
			std::stringstream ss;
			while (nextChar != '>')
			{
				ss << static_cast<char>(nextChar);

				nextChar = aStream.get();
				currentPos++;
			}
			ss << static_cast<char>(nextChar);

			oTokens.emplace_back(Token::Type::TAG, ss.str(), tokenStartPos);

		}
	}
}
