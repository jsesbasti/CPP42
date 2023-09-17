/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:14:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:36:08 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>

class Contact
{

private:
	std::string name;
	std::string	surename;
	std::string	nickname;
	std::string	description;
	std::string number;

public:
	//CONSTRUCTORS
	Contact( void );

	Contact( std::string first_name, std::string last_name, std::string nickname, std::string description, int phone_number );

	//DESTRUCTOR
	~Contact( void );

	//FUNCTIONS
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getDescription(void);
	std::string	getPhoneNumber(void);
	// Setters
	void		setFirstName(std::string first_name);
	void		setLastName(std::string last_name);
	void		setNickname(std::string nickname);
	void		setDescription(std::string description);
	void		setPhoneNumber(std::string phone_number);
};

#endif