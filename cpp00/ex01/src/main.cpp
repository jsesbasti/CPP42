/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:25:37 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/03 02:50:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

void	options(void)
{
	std::cout << "The options you must choose are: *ADD\n *SEARCH\n *EXIT" << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	inp;
	bool		end;

	end = true;
	options();
	while (end)
	{
		if (!std::getline(std::cin, inp))
			end = false;
		for (int i = 0; i < inp.length(); i++)
			inp[i] = toupper(inp[i]);
		if (inp.compare("EXIT") == 0)
			end = false;
	}
}