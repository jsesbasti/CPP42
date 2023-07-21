/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:04:17 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/17 08:29:46 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie	foo("foo");
	Zombie	*ne = NULL;

	foo.anounce();
	ne = newZombie("yes");
	ne->anounce();
	randomChump("boo");
	delete ne;
	return (0);
}