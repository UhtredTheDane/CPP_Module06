/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:07:07 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/20 17:39:39 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data = {.x = 10, .y = 12};
	uintptr_t test;
	Data *res;

	test = Serializer::serialize(&data);
	res = Serializer::deserialize(test);
	if (&data == res)
	{
		std::cout << "ptr: " << &data << std::endl;
		std::cout << "res: " << res << std::endl;
	}
	return (0);
}
