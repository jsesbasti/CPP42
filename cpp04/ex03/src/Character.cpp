/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:56:36 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/20 21:36:29 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : name("Bob"), currentIdx(0) {

	std::cout << "Default Character constructor called. Naming your Character Bob" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->flooridx = 0;
}

Character::Character( std::string _name ) : name(_name), currentIdx(0) {

	std::cout << "Character " << this->name << " created." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->flooridx = 0;

}

Character::Character( const Character& src ) {

	std::cout << "Copy Character constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		this->inventory[ i ] = NULL;
		if ( src.inventory[ i ] != NULL )
			this->inventory[ i ] = src.inventory[ i ]->clone();
	}
	this->floor = new AMateria*;
	if (src.floor != NULL)
	{
		for (int i = 0; i < src.flooridx; i++)
		{
			if (src.floor[i] != NULL)
				this->floor[i] = src.floor[i]->clone();
		}
	}
	this->currentIdx = src.currentIdx;
	this->flooridx = src.flooridx;

}

Character::~Character( void ) {

	std::cout << "Killing " << this->name << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		if ( this->inventory[ i ] != NULL )
			delete this->inventory[ i ];
	}
	if ( this->floor != NULL ) {
		for ( int i = 0; i < this->flooridx; i++ ) {
				delete this->floor[i];
		}
	}
}

Character&	Character::operator=( const Character& src) {

	std::cout << "HOLA SOY GAY" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->inventory[ i ] != NULL)
				delete this->inventory[ i ];
			this->inventory[ i ] = NULL;
			if (src.inventory[ i ] != NULL)
				this->inventory[ i ] = src.inventory[ i ]->clone();
		}
		if (this->floor)
		{
			for (int i = 0; i < this->flooridx; i++)
					delete this->floor[i];
		}
		this->currentIdx = src.currentIdx;
		this->flooridx = src.flooridx;
	}
	return (*this);

}

std::string const&	Character::getName( void ) const {

	return (this->name);

}

void	Character::use( int idx, ICharacter &target ) {

	if (idx < 0 || idx >= 4 || this->inventory[ idx ] == NULL)
		return ;
	this->inventory[ idx ]->use(target);

}

void	Character::unequip( int idx ) {

	if (idx < 0 || idx >= 4 || this->inventory[ idx ] == NULL)
		return ;
	std::cout << "Character: " << this->name << " just threwn " << this->inventory[ idx ]->getType() << " to the floor " << std::endl;
	addFloor( this->inventory[ idx ] );
	this->inventory[ idx ] = NULL;
}

void	Character::equip( AMateria *m ) {

	if (!m)
		return ;
	std::cout << "Character: " << this->name << " equip called with inventory = " << m->getType() << std::endl;
	for ( int i = 0; i < 4; i++ )
		if ( this->inventory[ i ] == m )
			return ;
	this->inventory[ this->currentIdx ] = m;
	for ( ; this->currentIdx < 4; this->currentIdx++ )
		if ( this->inventory[ this->currentIdx ] == NULL )
			break ;
	if ( this->inventory[ this->currentIdx ] != NULL )
		this->currentIdx = -1;

}

int	Character::getCurrentIdx( void ) const {
	return (this->currentIdx);
}

void	Character::addFloor( AMateria *m ) {
	AMateria **aux = NULL;

	if (this->floor == NULL) {
		this->floor = new AMateria*[1];
		this->floor[0] = m->clone();
		this->flooridx++;
		return ;
	}
	aux = new AMateria*[this->flooridx + 1];
	for (int i = 0; i < this->flooridx; i++)
	{
		aux[i] = this->floor[i]->clone();
		delete this->floor[i];
	}
	delete [] this->floor;
	aux[this->flooridx] = m->clone();
	this->floor = new AMateria*[this->flooridx + 1];
	for (int i = 0; i < this->flooridx + 1; i++)
	{
		this->floor[i] = aux[i]->clone();
		delete aux[i];
	}
	delete [] aux;
	this->flooridx++;
}