/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:54:18 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 03:46:18 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors -------------------------

ClapTrap::ClapTrap ( void ) {
    std::cout << "Default constructor called, setting name of ClapTrap to Bob" << std::endl;
    this->name = "Bob";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap ( const ClapTrap &src ) {
    *this = src;
}

ClapTrap::ClapTrap( std::string _name ) : name(_name) {
    std::cout << "ClapTrap " << _name << " created" << std::endl;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

// Destructors --------------------- 

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

//  Overloads ------------------

ClapTrap& ClapTrap::operator=( const ClapTrap &src ) {
    if (this != &src) {
        this->name = src.name;
        this->hit_points = src.hit_points;
        this->energy_points = src.energy_points;
        this->attack_damage = src.attack_damage;
    }
    return *this;
}

// Functions ------------------

void    ClapTrap::attack( const std::string& target ) {
    std::cout << "ClapTrap " << this->name << " attack " << target;
    std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}

void    ClapTrap::takeDamage( unsigned int amount ) {
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " take " << amount;
    std::cout << " points of damage. " << this->hit_points << " hit points left." << std::endl;
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    this->hit_points += amount;
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " rapired itself " << amount << " hit points. ";
    std::cout << this->hit_points << " left." << std::endl;
}