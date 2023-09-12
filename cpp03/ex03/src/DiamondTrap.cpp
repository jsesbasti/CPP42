/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:19:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 03:52:41 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap(), name("Bob") {
	std::cout << "Default constructor called, calling all default constructors" << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	this->ClapTrap::name = ClapTrap::name + "_clap_name";
}

DiamondTrap::DiamondTrap( std::string _name ) : ClapTrap(_name), ScavTrap(_name), FragTrap(_name) {
	this->name = _name;
	this->ClapTrap::name = _name + "_clap_name";

	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;

	std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) {
	*this = src;
}

DiamondTrap& DiamondTrap::operator= ( const DiamondTrap &src ) {
	std::cout << "Copy assignament operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hit_points = src.hit_points;
		this->attack_damage = src.attack_damage;
		this->energy_points = src.energy_points;
		this->ClapTrap::name = ClapTrap::name + "_clap_name";
	}
	return *this;
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "I am a DiamondTrap named " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}