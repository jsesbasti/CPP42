/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 03:44:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap bob("bob");

    bob.attack("william");
    bob.takeDamage( 5 );
    bob.beRepaired( 11 );
    bob.guardGate();
    return (0);
}