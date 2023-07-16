/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:52:20 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/16 15:14:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit) : _amount(initial_deposit) {
	return ;
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	this->_nbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount < withdrawal)
		return (false);
	else
	{
		this->_amount -= withdrawal;
		return (true);
	}
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	return ;
}

void	Account::displayAccountsInfos( void ) {
	return ;
}

Account::~Account() {
	return ;
}