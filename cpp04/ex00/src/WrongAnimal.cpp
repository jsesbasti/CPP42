/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:13:30 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 10:34:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Someone") {
	std::cout << "A wild WrongAnimal has appeared" << std::endl;
}

WrongAnimal::WrongAnimal( std::string _type ) : type(_type) {
	std::cout << "A wild WrongAnimal has appeared and is a... " << this->type << "?" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src ) {
	*this = src;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "The WrongAnimal has disappeared" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &src ) {
	if (this != &src) {
		*this = src;
	}
	return *this;
}

std::string	WrongAnimal::getType( void ) const {
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Someone wants to say something..." << std::endl;
}