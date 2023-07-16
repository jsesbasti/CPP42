/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:21:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/16 07:37:47 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"

class PhoneBook
{

private:
	Contact contact[8];

public:
	PhoneBook(void);
	~PhoneBook(void);
	//contact getter
	void	add_i( PhoneBook *pb, int i );
	void	display();
};

#endif