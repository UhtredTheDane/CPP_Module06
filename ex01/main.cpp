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
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	Data *ptr = (Data *) malloc(sizeof(Data));
	uintptr_t test = Serializer::serialize(ptr);
	Data *res = Serializer::deserialize(test);
	if (ptr == res)
	{
		printf("ptr: %p\n", ptr);
		printf("res: %p\n", res);
	}
	return (0);
}
