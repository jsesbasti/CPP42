/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 06:26:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:42:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"
#include	<iomanip>

static bool	valid_strnum( std::string str ) {
	for (std::string::size_type i = 0; i < str.length(); i++)
		if (std::isdigit(str[i]) == 0)
			return (false);
	return (true);
}

static std::string	getfield( std::string field, int mode ) {
	std::string	input;
	bool		valid;

	valid = false;
	while (!valid)
	{
		std::cout << "  " << field << ": ";
		if (!std::getline(std::cin, input))
			exit(0);
		if (input.empty())
			std::cout << "   The field cannot be empty" << std::endl;
		else if (mode == 1 && valid_strnum(input) == false)
			std::cout << "   Invalid input, the field '" << field \
			<< "' only accepts digits" << std::endl;
		else
			valid = true;
	}
	return (input);
}

Contact	create_contact( void ) {
	std::string	str;
	Contact		new_contact;

	str = getfield("first name", 0);
	new_contact.setFirstName(str);
	str = getfield("last name", 0);
	new_contact.setLastName(str);
	str = getfield("nickname", 0);
	new_contact.setNickname(str);
	str = getfield("description", 0);
	new_contact.setDescription(str);
	str = getfield("phone number", 1);
	new_contact.setPhoneNumber(str);
	return (new_contact);
}

static void	print_str_wide( std::string str ) {
	if (str.length() > 10)
		str.erase(9, str.length()).append(1, '.');
	std::cout << std::setw(10) << str;
}

void	print_contacts( PhoneBook phonebook ) {
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < phonebook.getsize(); i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
		print_str_wide(phonebook.findContact(i).getFirstName());
		std::cout << "|";
		print_str_wide(phonebook.findContact(i).getLastName());
		std::cout << "|";
		print_str_wide(phonebook.findContact(i).getNickname());
		std::cout << "|" << std::endl;
	}
}

void	search_contact( PhoneBook phonebook ) {
	std::string	str;
	short int	idx;
	bool		ok;

	if (phonebook.getsize() == 0)
	{
		std::cout << "   Phonebook is empty" << std::endl;
		return ;
	}
	print_contacts(phonebook);
	std::cout << "Select index: ";
	if (!std::getline(std::cin, str))
		exit(0);
	ok = valid_strnum(str);
	idx = 0;
	if (ok == true)
		idx = std::stoi(str);
	if (ok == false || idx < 0 || idx > phonebook.getsize() - 1)
	{
		std::cout << "   Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << phonebook.findContact(idx).getFirstName() << std::endl;
	std::cout << "Last name: " << phonebook.findContact(idx).getLastName() << std::endl;
	std::cout << "Nickname: " << phonebook.findContact(idx).getNickname() << std::endl;
	std::cout << "Phone number: " << phonebook.findContact(idx).getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << phonebook.findContact(idx).getDescription() << std::endl;
}