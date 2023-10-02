/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:02:46 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/28 15:22:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : cIdx(0) {
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->newMateria[ i ] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &src ) : cIdx(0) {
	for (int i = 0; i < 4; i++) {
		if (this->newMateria[ i ] != NULL)
			delete newMateria[ i ];
		newMateria[ i ] = NULL;
		if (src.newMateria[ i ] != NULL)
			this->newMateria[ i ] = src.newMateria[ i ]->clone();
	}
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->newMateria[ i ])
			delete newMateria[ i ];
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource & src ) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->newMateria[ i ] != NULL)
				delete newMateria[ i ];
			newMateria[ i ] = NULL;
			if (src.newMateria[ i ] != NULL)
				this->newMateria[ i ] = src.newMateria[ i ]->clone();
		}
		this->cIdx = src.cIdx;
	}
	return (*this);
}
	
void	MateriaSource::learnMateria( AMateria* materia) {
	if (this->cIdx == -1) {
		if ( materia != NULL)
			delete materia;
		return ;
	}
	for ( int i = 0; i < 4; i++ ) {
		if ( this->newMateria[ i ] == materia )
			return ;
	}
	this->newMateria[ this->cIdx ] = materia;
	this->cIdx = (this->cIdx + 1 >= 4) ? -1 : this->cIdx + 1 ;
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( this->newMateria[ i ] != NULL )
		{
			if ( this->newMateria[ i ]->getType().compare( type ) == 0 )
				return ( this->newMateria[ i ]->clone() );
		}
	}
	return ( 0 );
}
