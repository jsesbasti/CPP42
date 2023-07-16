/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:14:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/16 02:03:33 by jsebasti         ###   ########.fr       */
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
	Contact(void);

	Contact (std::string name, std::string surename, std::string nickname, std::string description, std::string number);

	//DESTRUCTOR
	~Contact(void);

	//FUNCTIONS
	void	print_info();
	void	print_name();
};

#endif