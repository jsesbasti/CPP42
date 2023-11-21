/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:44:10 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 12:34:20 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

# include "Data.hpp"
# include <iostream>

class Serializer
{
private:
	Serializer();
	Serializer( const Serializer &src );

	Serializer	&operator=( const Serializer &src );

	~Serializer();

public:
	static uintptr_t	serialize(Data *ptr);
	static Data		*deserialize(uintptr_t raw);
};

#endif