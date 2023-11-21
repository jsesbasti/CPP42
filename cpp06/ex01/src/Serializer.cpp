/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:37 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 12:16:56 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {
}

Serializer::~Serializer( void ) {
}

Serializer::Serializer( const Serializer &src ) {
	(void)src;
}

Serializer	&Serializer::operator=( const Serializer &src ) {
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}