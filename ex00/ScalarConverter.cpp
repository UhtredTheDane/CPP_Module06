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

//std::stringstream

#include "ScalarConverter.hpp"

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

static void convertInChar(long double first_value, bool nan, bool infp, bool infm)
{
	std::cout << "char: ";
	if (first_value < 0 || first_value > 127 || nan || infp || infm)
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

static void convertInInt(long double first_value, bool nan, bool infp, bool infm)
{
	std::cout << "int: ";
	if (first_value < INT_MIN || first_value > INT_MAX || nan || infp || infm)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(first_value);
	std::cout << std::endl;
}


void convertInFloat(long double first_value, bool nan, bool infp, bool infm)
{
	std::cout << "float: ";
	if (first_value < FLT_MAX * -1 || first_value > FLT_MAX)
		std::cout << "impossible";
	else if(nan)
		std::cout << "nanf";
	else if (infp)
		std::cout << "+inff";
	else if (infm)
		std::cout << "-inff";
	else
		std::cout << static_cast<float>(first_value) << "f";
	std::cout << std::endl;
}

static void convertInDouble(long double first_value, bool nan, bool infp, bool infm)
{
	double double_value;

	std::cout << "double: ";
	if (first_value < DBL_MAX * -1 || first_value > DBL_MAX)
		std::cout << "impossible";
	else if(nan)
		std::cout << "nan";
	else if (infp)
		std::cout << "+inf";
	else if (infm)
		std::cout << "-inf";
	else
		std::cout << static_cast<double>(first_value);
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	std::stringstream test;
	long double first_value;
	bool nan;
	bool infp;
	bool infm;

	first_value = 0;
	nan = false;
	infp = false;
	infm = false;
	if (value.compare("nan") == 0)
		nan = true;
	else if (value.compare("+inf") == 0)
		infp = true;
	else if (value.compare("-inf") == 0)
		infm = true;
	else
	{	
		test << value;	
		test >> first_value;
		if (!test.eof())
			std::cout << "Bad input" << std::endl;
	}
	convertInChar(first_value, nan, infp, infm);
	convertInInt(first_value, nan, infp, infm);
	convertInFloat(first_value, nan, infp, infm);
	convertInDouble(first_value, nan, infp, infm);
}
