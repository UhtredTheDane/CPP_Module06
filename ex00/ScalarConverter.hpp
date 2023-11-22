/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:04 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/22 14:07:11 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//std::stringstream
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

class ScalarConverter
{
	public:
		static void convert(std::string);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& toCopy);
		~ScalarConverter(void);
		ScalarConverter& operator=(ScalarConverter const& toAffect);
};

#endif
