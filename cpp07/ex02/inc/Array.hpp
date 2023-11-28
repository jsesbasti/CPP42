/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:08:44 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 12:38:09 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <iostream>

template <class T>
class Array
{
private:
	T				*array;
	unsigned int	size;

public:
	Array( void );
	Array( unsigned int n );
	Array( const Array & srcArray );
	~Array();

	Array	&operator=( const Array & srcArray );
	T		&operator[]( unsigned int pos ) const;

	unsigned int getSize( void ) const;
};

# include "Array.tpp"

#endif