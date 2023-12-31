/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:54:18 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/06 10:32:20 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->num = 0;
}

Fixed::Fixed( const Fixed &fix ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(fix.getRawBits());
}

Fixed& Fixed::operator =( const Fixed &fix ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fix)
        this->num = fix.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void    Fixed::setRawBits( int const raw ) {
    this->num = raw;
}