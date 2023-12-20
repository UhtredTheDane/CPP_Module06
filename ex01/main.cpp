/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:07:07 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/24 16:27:34 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdlib.h>

int main(void)
{
	Data *ptr = (Data *) malloc(sizeof(Data));
	uintptr_t test = Serializer::serialize(ptr);
	Data *res = Serializer::deserialize(test);
	if (ptr == res)
	{
		std::cout << "ptr: " << ptr << std::endl;
		std::cout << "res: " << res << std::endl;
	}
	return (0);
}
