/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:56:36 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/02 12:27:46 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : name("Bob"), currentIdx(0) {

	std::cout << "Default Character constructor called. Naming your Character Bob" << std::endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->flooridx = 0;
}

Character::Character( std::string _name ) : name(_name), currentIdx(0) {

	std::cout << "Character " << this->name << " created." << std::endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->flooridx = 0;

}

Character::Character( const Character& src ) {

	std::cout << "Copy Character constructor called" << std::endl;
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (src.inventory[ i ] != NULL)
			this->inventory[ i ] = src.inventory[ i ]->clone();
		else
			this->inventory[ i ] = NULL;
	}
	if (src.floor)
		this->floor = copyFloor(src.floor, src.flooridx);
	this->currentIdx = src.currentIdx;
	this->flooridx = src.flooridx;
}

Character::~Character( void ) {

	std::cout << "Killing " << this->name << std::endl;
	for ( int i = 0; i < MAX_INVENTORY; i++ ) {
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[ i ];
			this->inventory[i] = NULL;
		}
	}
	if ( this->floor != NULL ) {
		for ( int i = 0; i < this->flooridx; i++ )
			if (this->floor[i] != NULL)
				delete this->floor[i];
		delete [] this->floor;
		this->floor = NULL;
	}
}

Character&	Character::operator=( const Character& src) {

	if (this != &src) {
		for (int i = 0; i < MAX_INVENTORY; i++) {
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
			delete [] this->floor;
			this->floor = NULL;
		}
		if (src.floor)
			this->floor = copyFloor(src.floor, src.flooridx);
		this->currentIdx = src.currentIdx;
		this->flooridx = src.flooridx;
	}
	return (*this);

}

AMateria	**copyFloor( AMateria **srcFloor, int newFloorLen )
{
	AMateria	**newFloor;

	newFloor = new AMateria*[newFloorLen];
	for (int i = 0; i < newFloorLen; i++)
	{
		if (srcFloor[i] != NULL)
			newFloor[i] = srcFloor[i]->clone();
		else
			newFloor[i] = NULL;
	}
	return (newFloor);
}

std::string const&	Character::getName( void ) const {

	return (this->name);

}

void	Character::use( int idx, ICharacter &target ) {

	if (idx < 0 || idx >= 4 || this->inventory[ idx ] == NULL)
	{
		std::cout << "Please, don't try to use unequiped or inexistent materias 😇" << std::endl;
		return ;
	}
	this->inventory[ idx ]->use(target);

}

void	Character::equip( AMateria *m ) {

	if (m == NULL)
	{
		std::cout << "Can not equip an inexistent materia" << std::endl;
		return ;
	}
	for ( int i = 0; i < MAX_INVENTORY; i++ )
	{
		if ( this->inventory[ i ] == m )
		{
			std::cout << "This materia has been equiped before" << std::endl;
			return ;
		}
	}
	if (existMateriaInFloor( *m ))
	{
		std::cout << "This materia has been thrown before" << std::endl;
		return ;
	}
	if (this->currentIdx == -1)
	{
		std::cout << "No space left in the inventory, threwing the materia to the floor";
		addFloor( *m );
		return ;
	}
	for (; this->currentIdx < MAX_INVENTORY; this->currentIdx++ )
	{
		if ( this->inventory[ this->currentIdx ] == NULL )
		{
			this->inventory[ this->currentIdx ] = m;
			break ;
		}
	}
	std::cout << "Character: " << this->name << " equip called with inventory = " << m->getType() << std::endl;
	if ( this->currentIdx == MAX_INVENTORY - 1 && this->inventory[ this->currentIdx ] != NULL )
		this->currentIdx = -1;

}

void	Character::unequip( int idx ) {

	if (idx < 0 || idx >= MAX_INVENTORY || this->inventory[ idx ] == NULL)
	{
		std::cout << "Can not unequip an unequiped or inexistent materia" << std::endl;
		return ;
	}
	if (existMateriaInFloor( *this->inventory[ idx ] ))
	{
		this->inventory[ idx ] = NULL;
		return ;
	}
	std::cout << std::endl << "Character: " << this->name << " just threwn " << this->inventory[ idx ]->getType() << " to the floor " << std::endl << std::endl;
	addFloor( *this->inventory[ idx ] );
	this->inventory[ idx ] = NULL;
}

void	Character::addFloor( AMateria &m ) {
	
	this->floor = incrementFloorMem( this->floor, this->flooridx );
	this->floor[this->flooridx] = &m;
	this->flooridx++;
}

AMateria **incrementFloorMem( AMateria **floor, int floorLen )
{
	AMateria **aux = NULL;

	if (floor == NULL)
		return (new AMateria*[1]);
	aux = new AMateria*[floorLen + 1];
	for (int i = 0; i < floorLen; i++)
		aux[i] = floor[i];
	delete [] floor;
	return (aux);

}

bool	Character::existMateriaInFloor( AMateria& m )
{
	if (this->floor != NULL)
	{
		for ( int i = 0; i < this->flooridx; i++ )
			if ( this->floor[ i ] == &m )
				return (true);
	}
	return (false);
}

void	Character::printFloor( void ) const {
	if (!this->floor)
	{
		std::cout << "Floor empty" << std::endl;
		return ;
	}
	for (int i = 0; i < this->flooridx; i++)
		if (this->floor[i])
			std::cout << "The position " << i << " of the floor contains: " << this->floor[i]->getType() << std::endl;
}

void	Character::printMaterias( void ) const {
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->inventory[i] != NULL)
			std::cout << "The position " << i << " of the INV contains: " << this->inventory[i]->getType() << std::endl;
	}
}
