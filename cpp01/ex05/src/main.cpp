/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:04:17 by jsebasti          #+#    #+#             */
/*   Updated: 2023/08/15 19:58:52 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl  karen;
	std::string LevelOfAnnoyance;

	std::cin >> LevelOfAnnoyance;
	while (LevelOfAnnoyance != "EXIT")
	{
		if (std::cin.eof() == true)
			break;
		karen.complain(LevelOfAnnoyance);
		std::cin >> LevelOfAnnoyance;
	}
	return (0);
}