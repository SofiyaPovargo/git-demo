#include <iostream>
#include <string>
#include <algorithm>
//lab 10.1
void InputString(std::string& str) 
{
	std::cout << "Enter string: ";
	std::getline(std::cin, str);
}

std::string CopyString(std::string& input_str) 
{
	std::string str = input_str;
	return str;
}

void InputDelim(std::string& delim) 
{
	std::cout << "Enter delim: ";
	std::getline(std::cin, delim);
}

void PrintString(std::string str) 
{
	for (int i = 0; i < str.size(); ++i) 
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}

bool IsWordDigit(const std::string& word) 
{
	if (word.empty()) return false;
	int start = 0;
	if (word[0] == '-') 
	{
		start = 1;
	}
	for (int i = start; i < word.size(); ++i) 
	{
		if (!std::isdigit(word[i])) 
		{
			return false;
		}
	}
	return true;
}

void CheckString(std::string& str, std::string& delim) 
{
	int start = str.size() - 1;
	int end = str.size() - 1;
	std::string sub_str{};
	while (end >=0)
	{
		end = str.rfind(delim, start);
		std::string word = str.substr(end + 1, start - end);
		if (IsWordDigit(word)) 
		{
			str.erase(end, word.size() + 1);
			sub_str = word + delim + sub_str;
			start = end - 1;
		}
		else 
		{
			start = end - 1;
			--end;
		}
		
	}
	str = sub_str + str;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	std::string input_str;
	std::string str;
	std::string delim = " ";
	try {
		InputString(input_str);
		str = CopyString(input_str);
		InputDelim(delim);
		PrintString(str);
		CheckString(str, delim);
		PrintString(str);
	}
	catch (...) {

	}
	return 0;
}
