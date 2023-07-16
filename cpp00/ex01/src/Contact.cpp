/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:16:33 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/16 02:02:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ( std::string name, std::string surename, std::string nickname, std::string description, std::string number ) {
	this->name = name;
	this->surename = surename;
	this->nickname = nickname;
	this->description = description;
	this->number = number;
}

Contact::Contact () {
	return ;
}

Contact::~Contact() {
	return ;
}

void	Contact::print_info() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Surename: " << this->surename << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Description: " << this->description << std::endl;
	std::cout << "Number: " << this->number << std::endl;
}

void	Contact::print_name() {
	std::cout << "Name2: " << this->name << std::endl;
}