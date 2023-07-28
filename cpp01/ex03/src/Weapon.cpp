/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:49:06 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:20:30 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string _type) : type(_type) {
	return ;
}

Weapon::~Weapon() {
	return ;
}

std::string	Weapon::getType() const {
	return (this->type);
}

void	Weapon::setType( std::string _type ) {
	this->type = _type;
	return ;
}