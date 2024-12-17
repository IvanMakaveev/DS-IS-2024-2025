#include <stack>
#include <string>
#include <iostream>

bool isOpenBracket(char ch)
{
	return ch == '(' || ch == '[' || ch == '{';
}

bool isClosingBracketMatch(char open, char close)
{
	switch (open)
	{
	case '(':
		return close == ')';
	case '[':
		return close == ']';
	case '{':
		return close == '}';
	}

	return false;
}

bool isValid(const std::string& str)
{
	std::stack<char> brackets;

	for (char ch : str)
	{
		if (isOpenBracket(ch))
		{
			brackets.push(ch);
		}
		else 
		{
			if (brackets.empty() || !isClosingBracketMatch(brackets.top(), ch))
			{
				return false;
			}
			else
			{
				brackets.pop();
			}
		}
	}
	return brackets.empty();
}