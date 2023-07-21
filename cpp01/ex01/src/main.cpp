/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:04:17 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/17 08:55:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie	foo;
	Zombie	*ne = NULL;
	int	n = 5;

	foo.set_name("FOO");
	foo.anounce();
	ne = zombieHorde(n, "boss");
	for (int i = 0; i < n; i++)
		ne[i].anounce();
	delete[] ne;
	return (0);
}