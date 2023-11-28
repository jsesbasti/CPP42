/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:08 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 13:33:51 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base	*generate( void )
{
	int random_num = std::rand() % 3 + 1;

	switch (random_num)
	{
		case (1):
			return (new A());
		case (2):
			return (new B());
		case (3):
			return (new C());
	}
	return (NULL);
}

void	identify( Base *p )
{
	if (p == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cerr << "Unidentifyed class" << std::endl;
}

void	identify( Base &p ) {
	identify(&p);
}