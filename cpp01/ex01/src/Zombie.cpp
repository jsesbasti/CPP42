/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:49:06 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/17 08:53:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	return ;
}

void	Zombie::anounce( void ) {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " has died again." << std::endl;
}

void	Zombie::set_name( std::string _name) {
	this->name = _name;
}