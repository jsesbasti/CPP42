/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:25:37 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/07 09:07:55 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

PhoneBook::PhoneBook(){
};

PhoneBook::~PhoneBook(){
};

void	options(void) {
	std::cout << "\nThe options you must choose are: \n\t*ADD\t*SEARCH\t *EXIT\n";
}

int	main(void)
{
	int			num_contact = 0;
	PhoneBook	phonebook;
	std::string	inp;
	bool		end;

	end = true;
	while (end)
	{
		options();
		if (num_contact >= 8)
			num_contact = 0;
		if (!std::getline(std::cin, inp))
		{
			end = false;
			break ;
		}
		// for (size_t i = 0; i < inp.length(); i++)
		// 	inp[i] = toupper(inp[i]);
		if (inp.compare("EXIT") == 0)
			end = false;
		else if (inp.compare("ADD") == 0)
			add_contact(phonebook, num_contact);
		else if (inp.compare("SEARCH") == 0)
			search_contact(phonebook);
		num_contact++;
	}
}