/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 10:47:54 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal::Animal("Cat") {
	this->type = Animal::getType();
	std::cout << "A Meaw arrived from the street" << std::endl;
}

Cat::Cat( const Cat &src ) : Animal(src) {
	*this = src;
}

Cat::~Cat( void ) {
	std::cout << "The furry animal has gone with Anubis" << std::endl;
}

Cat& Cat::operator=( const Cat &src ) {
	if (this != &src) {
		this->Animal::type = src.type;
	}
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meaw! Meaw!" << std::endl;
}