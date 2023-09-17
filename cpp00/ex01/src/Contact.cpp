/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:16:33 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/17 06:35:37 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ){
}

Contact::Contact( std::string first_name, std::string last_name, std::string nickname, std::string description, int phone_number ) {
	this->name = first_name;
	this->surename = last_name;
	this->nickname = nickname;
	this->description = description;
	this->number = phone_number;
}

Contact::~Contact( void ){
}

std::string	Contact::getFirstName(void) {
	return (this->name);
}

std::string	Contact::getLastName( void ) {
	return (this->surename);
}

std::string	Contact::getNickname( void ) {
	return (this->nickname);
}

std::string	Contact::getDescription( void ) {
	return (this->description);
}

std::string	Contact::getPhoneNumber( void ) {
	return (this->number);
}

void	Contact::setFirstName( std::string first_name ) {
	this->name = first_name;
}

void	Contact::setLastName( std::string last_name ) {
	this->surename = last_name;
}

void	Contact::setNickname( std::string nickname ) {
	this->nickname = nickname;
}

void	Contact::setDescription( std::string description ) {
	this->description = description;
}

void	Contact::setPhoneNumber( std::string phone_number ) {
	this->number = phone_number;
}