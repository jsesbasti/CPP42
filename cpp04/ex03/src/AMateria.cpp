/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:50:18 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/18 10:44:30 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria &src ) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::AMateria( std::string const &type ) {
	std::cout << "AMateria Type constructor called" << std::endl;
	this->type = type;
}

AMateria& AMateria::operator=( const AMateria &src ) {
	std::cout << "AMateria overload of assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called" << std::endl;
}

void	AMateria::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" ;
}

const std::string& AMateria::getType( void ) const {
	return ( this->type );
}