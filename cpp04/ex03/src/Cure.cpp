/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:39:30 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 07:26:04 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) {
	std::cout << "Default Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure( const Cure &src ) {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure( void ) {
	std::cout << "Default Cure destructor called" << std::endl;
}

Cure& Cure::operator=( const Cure &src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone( void ) const {
	return (new Cure(*this));
}