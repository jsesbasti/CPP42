/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:16:35 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/25 11:45:33 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Not the expected amount of arguments" << std::endl;
		std::cout << "Usage: ./btc input_file" << std::endl;
		return (1);
	}

	BitcoinExchange::exchange( av[1] );
}