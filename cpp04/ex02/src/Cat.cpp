/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 11:19:32 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal::Animal("Cat") {
	this->brain = new Brain;
	std::cout << "A Meaw arrived from the street" << std::endl;
}

Cat::Cat( const Cat &src ) : Animal(src) {
	if (src.brain != NULL)
		this->brain = new Brain(*(src.brain));
	else
		this->brain = new Brain;
}

Cat::~Cat( void ) {
	delete this->brain;
	std::cout << "The furry animal has gone with Anubis" << std::endl;
}

Cat& Cat::operator=( const Cat &src ) {
	if (this != &src) {
		delete this->brain;
		this->Animal::type = src.type;
		if (src.brain != NULL)
			this->brain = new Brain(*(src.brain));
		else
			this->brain = new Brain;
	}
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meaw! Meaw!" << std::endl;
}


void	Cat::addIdea( std::string idea )
{
	if ( this->brain != NULL )
		this->brain->b_addIdea( idea );
}

std::string	Cat::getIdea( unsigned int idx ) const {
	if (this->brain != NULL)
		return (this->brain->b_getIdea( idx ));
	return ("");
}

unsigned int	Cat::getIndex( void ) const
{
	if ( this->brain != NULL )
		return ( this->brain->b_getIndex() );
	return ( -1 );
}

std::string	Cat::getCurrentIdea( void ) const
{
	if ( this->brain != NULL )
		return ( this->brain->b_getCurrentIdea() );
	return ( "" );
}