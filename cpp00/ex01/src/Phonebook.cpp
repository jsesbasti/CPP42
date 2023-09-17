/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:15:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:25:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	this->size = 0;
	this->idx = 0;
}

PhoneBook::PhoneBook( Contact contact ) {
	this->size = 0;
	this->contact[0] = contact;
}

PhoneBook::~PhoneBook( void ) {
}

void	PhoneBook::addContact( Contact contact ) {
	this->contact[this->idx] = contact;
	this->idx = (this->idx + 1) % 8;
	if (this->size < 8)
		this->size++;
}

Contact	PhoneBook::findContact( int n ) {
	return (this->contact[n]);
}

int	PhoneBook::getsize( void ) {
	return (this->size);
}