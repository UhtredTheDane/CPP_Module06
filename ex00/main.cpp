/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:30:53 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/22 15:10:54 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ScalarConverter::convert(argv[1]);
/*	cout << "char: " << ScalarConverter.convert() << std::endl;
	cout << "int: " << ScalarConverter.convert() << std::endl;
	cout << "float: " << ScalarConverter.convert() << std::endl;
	cout << "double: " << ScalarConverter.convert() << std::endl;*/
	return (0);
}
