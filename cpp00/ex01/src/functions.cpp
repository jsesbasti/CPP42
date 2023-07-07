/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:36:30 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/07 09:57:13 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	add_contact(PhoneBook phonebook, int i)
{
	std::string	inp;
	Contact		book;
	bool		end;

	book = phonebook.adress(i);
	end = true;
	while (end)
	{
		std::cout << "Please give the name of your contact: ";
		std::getline(std::cin, inp);
		book.set_name(inp);
		std::cout << "Please give the surename of your contact: ";
		std::getline(std::cin, inp);
		book.set_surename(inp);
		std::cout << "Please give a description of your contact: ";
		std::getline(std::cin, inp);
		book.set_des(inp);
		std::cout << "Please give the number of your contact: ";
		std::getline(std::cin, inp);
		book.set_number(inp);
		end = false;
	}
}

static int check_num(std::string num)
{
	for (size_t i = 0; i < num.length(); i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
	}
	return (0);
}

void	search_contact(PhoneBook phonebook)
{
	std::string	out;
	Contact		book;
	std::string	inp;
	int			pos;
	bool		end;

	end = true;
	while (end)
	{
		std::cout << "Please, what contact do you whant to see?: ";
		std::cin >> inp;
		while (check_num(inp))
		{
			std::cout << "Please, enter a number";
			std::cin >> inp;
		}
		pos = std::atoi((const std::string)inp);
		if (pos > 8)
			std::cout << "Please think a littlebit, how I'm gonna let you see more people than the people that you know?\n" << std::endl;
		else if (pos < 1)
			std::cout << "Please tell me how you can have " << pos << " friends, beacause it's impressionant!\n" << std::endl;
		book = phonebook.adress(pos - 1);
		out = book.get_name();
		std::cout << out;
		out = book.get_surename();
		std::cout << out;
		end = false;
	}
}