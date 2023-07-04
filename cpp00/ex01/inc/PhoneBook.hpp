/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:21:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/04 18:05:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"

class PhoneBook
{

private:
	Contact book[8];

public:
	//contact getter
	Contact contact(int i);
		return (book[i]);
	PhoneBook(void);
	~PhoneBook(void);
	
};

#endif