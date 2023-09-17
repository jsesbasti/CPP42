/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:25:37 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:31:13 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"functions.hpp"

static void	print_options( void )
{
	std::cout << "Allowed options:\n *   ADD\n *   SEARCH\n *   EXIT" << std::endl;	
}

int	main( void )
{
	PhoneBook	phonebook;
	std::string	input;
	bool		play;

	play = true;
	print_options();
	while (play)
	{
		input = "a";
		if (!std::getline(std::cin, input) || input.compare("EXIT") == 0)
			play = 0;
		else if (input.compare("ADD") == 0)
			phonebook.addContact(create_contact());
		else if (input.compare("SEARCH") == 0)
			search_contact(phonebook);
		else
		{
			std::cout << "Invalid option" << std::endl;
			print_options();
		}
	}
	return (0);
}