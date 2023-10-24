/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 19:01:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
    FragTrap bob;
    int i = 0;

    bob.attack("william");
    bob.takeDamage( 5 );
    bob.beRepaired( 11 );
    bob.highFivesGuys();
    while (i < 10)
    {
        bob.attack("himself");
        bob.takeDamage( bob.getAttackDamage() );
        i++;
    }
    return (0);
}