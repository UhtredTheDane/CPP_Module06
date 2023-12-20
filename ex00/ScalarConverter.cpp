/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:58 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/22 17:25:17 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip> 

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(ScalarConverter const& toCopy)
{
	*this = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{

}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& toAffect)
{
	(void) toAffect;
	return (*this);
}

static void convertInChar(long double first_value, int symbol)
{
	std::cout << "char: ";
	if (first_value < 0 || first_value > 127 || symbol > 1)
		std::cout << "impossible";
	else
	{
		if ((first_value >= 0 && first_value <= 31) || first_value == 127)
			std::cout << "not displayable";
		else
			std::cout << static_cast<char>(first_value);
	}
	std::cout << std::endl;
}

static void convertInInt(long double first_value, int symbol)
{
	std::cout << "int: ";
	if (first_value < INT_MIN || first_value > INT_MAX || symbol > 1)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(first_value);
	std::cout << std::endl;
}

static void convertInFloat(long double first_value, int symbol)
{
	std::cout << "float: ";
	if (first_value < FLT_MAX * -1 || first_value > FLT_MAX)
		std::cout << "impossible";
	else if(symbol == 2)
		std::cout << "nanf";
	else if (symbol == 3)
		std::cout << "+inff";
	else if (symbol == 4)
		std::cout << "-inff";
	else
	{
		std::cout << static_cast<float>(first_value);
		if (symbol == 1 && first_value < 1000000)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;
}

static void convertInDouble(long double first_value, int symbol)
{
	std::cout << "double: ";
	if (first_value < DBL_MAX * -1 || first_value > DBL_MAX)
		std::cout << "impossible";
	else if(symbol == 2)
		std::cout << "nan";
	else if (symbol == 3)
		std::cout << "+inf";
	else if (symbol == 4)
		std::cout << "-inf";
	else
	{
		std::cout << static_cast<double>(first_value);
		if (symbol == 1 && first_value < 1000000)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

static int checkSymbol(std::string value)
{
	if (value.compare("nan") == 0 || value.compare("nanf") == 0)
		return (2);
	else if (value.compare("+inf") == 0)
		return (3);
	else if (value.compare("-inf") == 0)
		return (4);
	return (0);
}

static bool isWholeNumber(std::string value)
{
	size_t pos;
	const char *str;

	pos = value.find('.');
	if (pos == std::string::npos)
		return (true);
	else
	{
		str = value.c_str();
		while (*(++str + pos) != '\0')
		{
			if (*(str + pos) != '0' && *(str + pos) != 'f')
				return (false);
		}
	}
	return (true);
}

void ScalarConverter::convert(std::string value)
{
	std::stringstream test;
	std::string remainder;
	long double first_value;
	int symbol;

	first_value = 0;
	symbol = checkSymbol(value);
	if (!symbol)
	{
		if (isWholeNumber(value))
			symbol = 1;
		test << value;
		test >> first_value;
		test >> remainder;
		if (!test.eof() || (remainder.size() > 0 && remainder.compare("f")))
		{
			std::cout << "Bad input" << std::endl;
			return;
		}
	}
	convertInChar(first_value, symbol);
	convertInInt(first_value, symbol);
	convertInFloat(first_value, symbol);
	convertInDouble(first_value, symbol);
}
