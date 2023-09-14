/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:34:48 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 08:41:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) : idx(0) {
	std::cout << "A brain for an animal has been created" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		this->ideas[i] = "(Default idea)";
	}
}

Brain::Brain( std::string idea ) : idx(1) {
	this->ideas[0] = idea;
	for (int i = 1; i < MAX_IDEAS; i++) {
		this->ideas[i] = "(Default idea)";
	}
}

Brain::Brain( const Brain &src ) {
	for (int i = 0; i < MAX_IDEAS; i++) {
		this->ideas[i] = std::string(src.ideas[i]);
	}
	this->idx = src.idx;
}

Brain::~Brain( void ) {
	std::cout << "This brain has been emptied by an Alien" << std::endl;
}

Brain& Brain::operator=( const Brain &src ) {
	if (this != &src) {
		for (int i = 0; i < MAX_IDEAS; i++) {
			this->ideas[i] = src.ideas[i];
		}
		this->idx = src.idx;
	}
	return *this;
}


std::string Brain::b_getIdea( unsigned int _idx ) const {
	if (_idx >= MAX_IDEAS) {
		return ("Error the index is bigger than your brain capacity");
	}
	return ( this->ideas[ _idx ] );
}

void		Brain::b_addIdea( std::string idea ) {
	this->ideas[ this->idx ] = idea;
	if (this->idx + 1 >= MAX_IDEAS)
		this->idx = 0;
	else 
		this->idx++;
}


std::string		 Brain::b_getCurrentIdea( void ) const {
	return ( this->ideas[ this->idx ] );
}

unsigned int	Brain::b_getIndex( void ) const {
	return ( this->idx );
}
