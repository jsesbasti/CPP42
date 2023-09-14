/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 16:05:09 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Someone") {
	std::cout << "A wild animal has appeared" << std::endl;
}

Animal::Animal( std::string _type ) : type(_type) {
	std::cout << "A wild animal has appeared and is a... " << this->type << std::endl;
}

Animal::Animal( const Animal &src ) {
	*this = src;
}

Animal::~Animal( void ) {
	std::cout << "The animal has disappeared" << std::endl;
}

Animal& Animal::operator=( const Animal &src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

std::string	Animal::getType( void ) const {
	return (this->type);
}
