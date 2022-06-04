#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace Lexer
{
	void Lex(std::ifstream& aStream, std::vector<Token>& oTokens)
	{
		int currentPos = 0;
		char nextChar;
		while (aStream.get(nextChar))
		{
			int tokenStartPos = currentPos;

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
					ss << nextChar;

					aStream.get(nextChar);
					currentPos++;
				}
				ss << nextChar;

				oTokens.emplace_back(Token::Type::TAG, ss.str(), tokenStartPos);

			}
			else
			{
				std::cout << "While lexing ignoring character: " << nextChar << "(" << static_cast<int>(nextChar) << ") \n";
			}
		}
	}
}

