/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 22:39:04 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap bob("bob");

    bob.attack("william");
    bob.takeDamage( 5 );
    bob.beRepaired( 11 );
    return (0);
}