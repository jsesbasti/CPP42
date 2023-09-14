/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 12:50:07 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal::Animal("Dog") {
	std::cout << "A WoffWoff has entered in the chat" << std::endl;
	this->type = Animal::getType();
	this->brain = new Brain;
}

Dog::Dog( const Dog &src ) : Animal(src) {
	if (src.brain != NULL)
		this->brain = new Brain(*(src.brain));
	else
		this->brain = new Brain;
}

Dog::~Dog( void ) {
	delete this->brain;
	std::cout << "Our besti leave us" << std::endl;
}

Dog& Dog::operator=( const Dog &src ) {
	if (this != &src) {
		delete this->brain;
		this->type = src.type;
		if (src.brain != NULL)
			this->brain = new Brain(*(src.brain));
		else
			this->brain = new Brain;
	}
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "Woff! Woff!" << std::endl;
}

void	Dog::addIdea( std::string idea )
{
	if ( this->brain != NULL )
		this->brain->b_addIdea( idea );
}

std::string	Dog::getIdea( unsigned int idx ) const {
	if (this->brain != NULL)
		return (this->brain->b_getIdea( idx ));
	return ("");
}

unsigned int	Dog::getIndex( void ) const
{
	if ( this->brain != NULL )
		return ( this->brain->b_getIndex() );
	return ( -1 );
}

std::string	Dog::getCurrentIdea( void ) const
{
	if ( this->brain != NULL )
		return ( this->brain->b_getCurrentIdea() );
	return ( "" );
}