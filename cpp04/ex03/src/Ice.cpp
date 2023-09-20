/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:05:56 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 07:18:05 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) {
	std::cout << "Default Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice( const Ice &src ) {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice( void ) {
	std::cout << "Default Ice destructor called" << std::endl;
}

Ice& Ice::operator=( const Ice &src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

void	Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone( void ) const {
	return (new Ice(*this));
}