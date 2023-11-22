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

static void convertInChar(int int_value)
{
	std::cout << "char: ";
	if (int_value < 0 || int_value > 127)
		std::cout << "impossible";
	else
	{
		if ((int_value >=0 && int_value <= 31) || int_value == 127)
			std::cout << "not displayable";
		else
			std::cout << static_cast<char>(int_value);
	} 
	std::cout << std::endl;
}
/*
static void convertInInt()
{
	
}*/

void ScalarConverter::convert(std::string value)
{
	std::stringstream test;
	float int_value;
	
	test << value;	
	test >> int_value;
	std::cout << int_value << std::endl;
	if (!test.eof())	
		std::cout << "Bad input" << std::endl;
	

	
	/*test.str("");
	test.clear();
	test << value;	
	float float_value = 0.0f;
	test >> float_value;

	test.str("");
	test.clear();
	test << value;	
	double double_value;
	test >> double_value;*/

	convertInChar(int_value);
	/*std::cout << "int: " << int_value << std::endl;
	std::cout << "float: " << float_value + 0.0 << std::endl;
	std::cout << "double: " << double_value << std::endl;*/
}
