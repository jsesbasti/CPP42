/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:17:48 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 12:33:34 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main( void )
{
	Data		*ptr;
	Data		*newPtr;
	uintptr_t	raw;
	int			number;

	number = 49;
	ptr = new Data;
	ptr->c = number;
	ptr->i = number;
	ptr->ptr = &number;
	std::cout << "[ BEFORE ] Data *ptr stats -> ptr: " << ptr << std::endl;
	std::cout << " && ptr->c: " << ptr->c << std::endl;
	std::cout << " && ptr->i: " << ptr->i << std::endl;
	std::cout << " && ptr->ptr: " << ptr->ptr << std::endl;
	std::cout << " && *( ptr->ptr ): " << *(ptr->ptr) << std::endl;
	std::cout << std::endl;

	raw = Serializer::serialize(ptr);
	newPtr = Serializer::deserialize(raw);

	std::cout << "[ AFTER ] Data *newPtr stats -> newPtr: " << newPtr << std::endl;
	std::cout << " && newPtr->c: " << newPtr->c << std::endl;
	std::cout << " && newPtr->i: " << newPtr->i << std::endl;
	std::cout << " && newPtr->ptr: " << newPtr->ptr << std::endl;
	std::cout << " && *( newPtr->ptr ): " << *(newPtr->ptr) << std::endl;
	std::cout << std::endl;

	delete ptr;

	return (0);
}