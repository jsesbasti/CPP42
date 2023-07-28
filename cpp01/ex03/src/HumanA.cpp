/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:33:49 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:32:52 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon &_weapon ) : weapon(&_weapon) {
	if (_name.empty())
	{
		std::cout << "Setting a default name to your Human..." << std::endl;
		_name = "John";
	}
	this->name = _name;
	return ;
}

HumanA::~HumanA() {
	return ;
}

void	HumanA::attack() {
	if (this->weapon == NULL)
	{
		std::cout << "Please give a weapon to " << this->name << std::endl;
		return ;
	}
	std::cout << this->name << " attack with his " << this->weapon->getType() << std::endl;
}