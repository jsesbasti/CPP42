/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:08:32 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:32:43 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string _name ) {
	if (_name.empty())
	{
		std::cout << "Setting a default name to your Human..." << std::endl;
		_name = "John";
	}
	this->name = _name;
	return ;
}

HumanB::~HumanB() {
	return ;
}

void	HumanB::attack() {
	if (this->weapon == NULL)
	{
		std::cout << "Please give a weapon to " << this->name << std::endl;
		return ;
	}
	std::cout << this->name << " attack with his " << this->weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon &_weapon ) {
	this->weapon = &_weapon;
	return ;
}