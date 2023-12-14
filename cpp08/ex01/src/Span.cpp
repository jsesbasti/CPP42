/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:04:12 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/14 11:41:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) {
	this->size = 0;
}

Span::Span( unsigned int _N ) {
	this->size = _N;
}

Span::~Span( void ) {
	this->vec.clear();
}

Span::Span( const Span & srcSpan ) : vec( srcSpan.vec ) {
	this->size = srcSpan.getSize();
}


Span	&Span::operator=( const Span & srcSpan ) {
	if (this != &srcSpan)
	{
		this->vec.clear();
		this->vec = srcSpan.vec;
		this->size = srcSpan.getSize();
	}
	return (*this);
}

void	Span::addNumber( int _N ) {
	if (this->getArgs() >= this->size)
		throw std::out_of_range("The array is full.");
	this->vec.insert(_N);
}

int	Span::getNumber( unsigned int pos ) const
{
	std::multiset< int >::const_iterator it = this->vec.cbegin();

	if ( pos >= this->vec.size() )
		throw std::out_of_range( "Invalid index" );
	for ( unsigned int n = 0; n < this->vec.size(); n++ )
	{
		if ( n == pos )
			return ( *it );
		it++;
	}
	return ( 0 );
}

unsigned int	Span::getSize( void ) const {
	return (this->size);
}

unsigned int	Span::getArgs( void ) const {
	return (this->vec.size());
}

long	Span::shortestSpan( void ) {
	long	last = 0;
	long	minSpan = std::numeric_limits< unsigned int >::max();

	if (this->getArgs() < 2)
		throw std::logic_error("Can't find shortest span with less than 2 numbers");
	for (std::multiset< int >::const_iterator it = this->vec.cbegin(); it != this->vec.cend(); it++)
	{
		if (it != this->vec.cbegin() && std::abs( *it - last ) < minSpan)
			minSpan = std::abs(*it - last);
		last = *it;
	}
	return (minSpan);
}

long	Span::longestSpan( void ) {
	std::multiset< int >::const_iterator	min;
	std::multiset< int >::const_iterator	max;

	if (this->getArgs() < 2)
		throw std::logic_error("Can't find shortest span with less than 2 numbers");
	min = std::min_element(this->vec.begin(), this->vec.end());
	max = std::max_element(this->vec.begin(), this->vec.end());

	return (std::abs( static_cast<long>(*max) - static_cast<long>(*min)));
}

void	Span::fill( unsigned int n )
{
	if ( static_cast< long >( this->getArgs() ) \
		+ static_cast< long >( n ) > static_cast< long >( this->size ) )
		throw std::length_error( "Length is too long" );
	srand( time( NULL ) );
	for ( unsigned int i = 0; i < n; i++ )
		this->vec.insert( rand() );
}

void	Span::fill( int start, int end )
{
	long	len;
	long	totalSize;

	len = std::abs( static_cast< long >( start ) - end );
	if ( len > this->size )
		throw std::length_error( "Length is too long" );
	totalSize = len + static_cast< long >( this->vec.size() );
	if ( totalSize > static_cast< long >( this->size ) )
		throw std::length_error( "Length is too long" );
	start = start < end ? start : end;
	for ( long i = 0; i < len; i++ )
		this->vec.insert( start + i );
}

std::ostream&	operator<<( std::ostream& out, const Span& span )
{
	out << "Max size: " << span.getSize() \
		<< " && Current size: " << span.getArgs() \
		<< " && Numbers: ";
	for ( unsigned int i = 0; i < span.getArgs(); i++ )
	{
		out << span.getNumber( i );
		if ( i + 1 < span.getSize() )
			out << ", ";
	}
	return ( out );
}
