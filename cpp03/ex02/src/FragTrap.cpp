/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:03 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 16:52:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap ( void ) : ClapTrap("Bob") {
	std::cout << "Default constructor called, calling all default constructors" << std::endl;
	this->attack_damage = 30;
	this->energy_points = 100;
	this->hit_points = 100;
}

FragTrap::FragTrap( std::string _name ) : ClapTrap(_name) {
	this->name = _name;
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
}

FragTrap::FragTrap ( const FragTrap &src ) {
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap &src ) {
	if (this != &src) {
		this->name = src.name;
		this->attack_damage = src.attack_damage;
		this->energy_points = src.energy_points;
		this->hit_points = src.hit_points;
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " request a High Five with a positive response." << std::endl;
}