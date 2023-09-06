/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:08:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/06 02:15:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void	Harl::complain( std::string level ) {
	std::string levels[4] = { "DEBUG" , "INFO", "WARNING", "ERROR" };
	int			i;

	i = 0;
	while (i <= 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			this->debug();
			i = 1;
		case 1:
			this->info();
			i = 2;
		case 2:
			this->warning();
			i = 3;
		case 3:
			this->error();
			break;
		default:
			std::cout << "Complainig about nothing" << std::endl;
	}
	return ;
}

void	Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
