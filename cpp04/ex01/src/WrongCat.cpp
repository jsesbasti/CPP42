/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:11:04 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 16:21:20 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal::WrongAnimal("WrongCat") {
	this->type = WrongAnimal::getType();
	std::cout << "A Cow arrived from the space" << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal(src) {
	*this = src;
}

WrongCat::~WrongCat( void ) {
	std::cout << "The not so furry animal has not gone with Ra" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &src ) {
	if (this != &src) {
		this->WrongAnimal::type = "WrongCat";
	}
	return *this;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "MUUUUU! MUUUUU!" << std::endl;
}