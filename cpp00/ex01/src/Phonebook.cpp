/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:15:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/17 06:30:54 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
};

PhoneBook::~PhoneBook(){
};

std::string  add_info( std::string msg )
{
	std::string dest;
	
	std::cout << msg;
	while (42)
	{
		std::getline(std::cin, dest);
		dest.erase(0, dest.find_first_not_of(" \t\v\f\r"));
		while (isspace(dest[dest.length() - 1]))
			dest.erase(dest.find_last_not_of(" \t\v\r\f") + 1, dest[dest.length() - 1]);
		if (dest.empty())
			std::cout << "Empty field not valid! Please, try again." << std::endl << msg;
		else
			break ;
	}
	return (dest);
}

bool	check_num(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0'|| str[i] > '9')
		{
			std::cout << str[i];
			return (false);
		}
	}
	return (true);
}

std::string  add_num( std::string msg )
{
	std::string dest;
	
	std::cout << msg;
	while (42)
	{
		std::getline(std::cin, dest);
		dest.erase(0, dest.find_first_not_of(" \t\v\f\r"));
		while (isspace(dest[dest.length() - 1]))
			dest.erase(dest.find_last_not_of(" \t\v\r\f") + 1, dest[dest.length() - 1]);
		if (dest.empty())
			std::cout << "Empty field not valid! Please, try again." << std::endl << msg;
		else if (check_num(dest) == false)
			std::cout << " Is not a valid number! Please, try again." << std::endl << msg;
		else
			break ;
	}
	return (dest);
}

void    PhoneBook::add_i( PhoneBook *pb, int i )
{
	Contact new_contact(add_info("First name: "), add_info("Last name: "),
						add_info("Nickname: "),add_info("Description: "),
						add_num("Phone Number: "));
	pb->contact[i] = new_contact;
}

void	PhoneBook::display()
{
	bool		end;
	bool		check;
	std::string	inp;
	int			i;

	i = -1;
	end = true;
	while (end)
	{
		check = true;
		std::cout << "Please enter an index from 1 to 8: ";
		if (!std::getline(std::cin, inp) || inp.empty() || check_num(inp) == false)
			std::cout << " Is not valid! Please give a valid index" << std::endl;
		else
			i = std::stoi(inp) - 1;
		if (i >= 0 && i < 8)
		{
			this->contact[i].print_info();
			while (check)
			{
				std::cout << "Do you want to see another contact? [y] / Default:[n] : ";
				if (!std::getline(std::cin, inp) || inp.empty() || !inp.compare("n"))
				{
					end = false;
					check = false;
				}
				else if (!inp.compare("y"))
					check = false;
				else
					std::cout << "Please give a valid input" << std::endl;
			}
		}
		else
			std::cout << "Please give a valid index" << std::endl;
	}
}