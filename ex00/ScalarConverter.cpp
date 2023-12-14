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

static void convertInFloat(std::string& value)
{
	std::stringstream test;
	float float_value;

	test << value;	
	test >> float_value;
	std::cout << "float: " << float_value << "f" << std::endl;
}

static void convertInDouble(std::string& value)
{
	std::stringstream test;
	double double_value;

	test << value;	
	test >> double_value;
	std::cout << "double: " << double_value << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	std::stringstream test;
	int int_value;
	double coco = 1.79769e+308;
	std::cout << coco << std::endl;
	test << value;	
	test >> int_value;
	if (!test.eof())
		std::cout << "Bad input" << std::endl;
	std::cout << std::numeric_limits<long>::max() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;
	std::cout << std::numeric_limits<double>::max() << std::endl;
	if (int_value > 2147483647 || int_value < -2147483648)
	{

	}

	//long coco = 9223372036854775808;
	//std::cout << coco << std::endl;
	convertInChar(int_value);
	std::cout << "int: " << int_value << std::endl;
	convertInFloat(value);
	convertInDouble(value);
}
