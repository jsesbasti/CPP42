/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:16:35 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/10 11:36:05 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Not the expected amount of arguments" << std::endl;
		std::cout << "Usage: ./RNP \"operation in Reverse Polish Notation\"" << std::endl;
		return (1);
	}

	RPN::rpn( av[1] );
}