/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:03 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 16:15:55 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) : ClapTrap() {
	std::cout << "Default constructor called, calling all default constructors" << std::endl;
	this->name = "Bob";
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap( std::string _name ) : ClapTrap(_name) {
	this->name = _name;
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap ( const ScavTrap &src ) {
	*this = src;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &src ) {
	if (this != &src) {
		this->name = src.name;
		this->attack_damage = src.attack_damage;
		this->energy_points = src.energy_points;
		this->hit_points = src.hit_points;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode" << std::endl;
}

void    ScavTrap::attack( const std::string& target ) {
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead." << std::endl;
		return ;
	}
	if (energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy_points left." << std::endl;
		return ;
	}
    std::cout << "ScavTrap " << this->name << " attack " << target;
    std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}