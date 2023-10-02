/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/02 14:40:32 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
    DiamondTrap ash( "Ash" );
    ClapTrap    gay = ash;

    ash.whoAmI();

    ash.attack( "the air" );
    gay.attack( "Heteros" );
    while (ash.getEnergyPoints() > 0)
        ash.beRepaired( 10 );

    std::cout << ash << std::endl;

    return 0;
}