/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:04:17 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/06 02:40:43 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int ac, char **av )
{
	Harl  karen;

	if (ac != 2)
		return (1);
	std::string LevelOfAnnoyance = av[1];
	if (LevelOfAnnoyance != "EXIT")
		karen.complain(LevelOfAnnoyance);
	return (0);
}