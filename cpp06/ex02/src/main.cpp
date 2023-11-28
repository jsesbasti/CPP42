/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:01 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 13:38:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <ctime>

int	main( void )
{
	std::srand(std::time(0));

	Base *a = generate();
	identify(*a);
	identify(a);
	std::cout << std::endl;

	Base *b = generate();
	identify(*b);
	identify(b);
	std::cout << std::endl;

	Base *c = generate();
	identify(*c);
	identify(c);
	std::cout << std::endl;

	Base *d = generate();
	identify(*d);
	identify(d);
	std::cout << std::endl;
		

	Base *f = NULL;
	identify(f);
	identify(*f);
	delete	a;
	delete	b;
	delete	c;
	delete	d;
	return (0);
}