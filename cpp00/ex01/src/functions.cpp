/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:36:30 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/04 18:06:50 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

void	add(PhoneBook phonebook, int i)
{
	std::string	inp;
	Contact		book;
	bool		end;

	end = true;
	while (end)
	{
		std::cout << "Please give the name of your contact: ";
		std::getline(std::cin, inp);
		book = phonebook.contact(i);

	}
}