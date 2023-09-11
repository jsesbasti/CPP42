/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:03 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 22:50:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string _name ) : ClapTrap(_name) {
	this->name = _name;
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " request a High Five with a positive response." << std::endl;
}