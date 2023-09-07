/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:54:18 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 14:21:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed( const int n ) : num( n << floating ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : num( std::roundf( n * ( 1 << floating ) ) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fix ) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fix.getRawBits());
}

Fixed&	Fixed::operator=( const Fixed &fix ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->num = fix.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->num;
}

void	Fixed::setRawBits( int const raw ) {
	this->num = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << floating );
}

int		Fixed::toInt( void ) const {
	return this->num >> floating;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}

// ---------------- Arithmetic ---------------

Fixed	Fixed::operator+( const Fixed &fix ) const {
	return ( Fixed(this->toFloat() + fix.toFloat()) );
}

Fixed	Fixed::operator-( const Fixed &fix ) const {
	return ( Fixed(this->toFloat() - fix.toFloat()) );
}

Fixed	Fixed::operator*( const Fixed &fix ) const {
	return ( Fixed(this->toFloat() * fix.toFloat()) );
}

Fixed	Fixed::operator/( const Fixed &fix ) const {
	return ( Fixed(this->toFloat() / fix.toFloat()) );
}

// ---------------- Comparision ---------------

bool	Fixed::operator>( const Fixed &fix ) const {
	return ( this->getRawBits() > fix.getRawBits() );
}

bool	Fixed::operator<( const Fixed &fix ) const {
	return ( this->getRawBits() < fix.getRawBits() );
}

bool	Fixed::operator>=( const Fixed &fix ) const {
	return ( this->getRawBits() >= fix.getRawBits() );
}

bool	Fixed::operator<=( const Fixed &fix ) const {
	return ( this->getRawBits() <= fix.getRawBits() );
}

bool	Fixed::operator!=( const Fixed &fix ) const {
	return ( this->getRawBits() != fix.getRawBits() );
}

bool	Fixed::operator==( const Fixed &fix ) const {
	return ( this->getRawBits() == fix.getRawBits() );
}

// ---------------- Increment/Decrement ------------

Fixed&	Fixed::operator++( void ) {
	++this->num;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed tmp( *this );
	tmp.num = this->num++;
	return tmp;
}

Fixed&	Fixed::operator--( void ) {
	--this->num;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed tmp( *this );
	tmp.num = this->num--;
	return tmp;
}

//------------- Max & Min ---------------

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
