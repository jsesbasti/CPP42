/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:21:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:36:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"

class PhoneBook
{

private:
	Contact contact[8];
	int	size;
	int	idx;

public:
	PhoneBook( void );
	PhoneBook( Contact contact );
	
	~PhoneBook( void );
	//contact getter
	int		getsize( void );
	Contact	findContact( int n );
	void	addContact( Contact contact );
};

#endif