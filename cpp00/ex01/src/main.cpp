/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:25:37 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/04 18:07:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

void	options(void)
{
	std::cout << "The options you must choose are: *ADD\n *SEARCH\n *EXIT" << std::endl;
}

int	main(void)
{
	static int	num_contact = 0;
	PhoneBook	phonebook;
	std::string	inp;
	bool		end;

	end = true;
	options();
	while (end)
	{
		if (!std::getline(std::cin, inp))
			end = false;
		for (size_t i = 0; i < inp.length(); i++)
			inp[i] = toupper(inp[i]);
		if (inp.compare("EXIT") == 0)
			end = false;
		else if (inp.compare("ADD"))
			add_contact(phonebook, num_contact);
		num_contact++;
	}
}