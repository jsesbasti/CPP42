/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 10:33:22 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal::Animal("Dog") {
	std::cout << "A WoffWoff has entered in the chat" << std::endl;
	this->type = Animal::getType();
}

Dog::Dog( const Dog &src ) : Animal(src) {
	*this = src;
}

Dog::~Dog() {
	std::cout << "Our besti leave us" << std::endl;
}

Dog& Dog::operator=( const Dog &src ) {
	if (this != &src) {
		this->Animal::type = src.type;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woff! Woff!" << std::endl;
}