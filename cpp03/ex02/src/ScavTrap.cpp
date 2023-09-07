/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:03 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 22:38:41 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string _name ) : ClapTrap(_name) {
	this->name = _name;
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode" << std::endl;
}