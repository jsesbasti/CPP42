/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:10:22 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 12:38:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

template <class T>
Array<T>::Array( void ) : size(0)
{
	this->array = NULL;
}

template <class T>
Array<T>::Array( unsigned int n ) : size(n)
{
	this->array = new T[this->size];
}

template <class T>
Array<T>::Array( const Array & srcArray )
{
	this->size = srcArray.getSize();
	this->array = new T[this->size];

	for (unsigned int i = 0; i < this->size; i++)
		this->array[i] = srcArray[i];
}

template <class T>
Array<T>::~Array( void )
{
	if (this->size != 0)
		delete [] this->array;
}

template <class T>
Array<T> &Array<T>::operator=( const Array & srcArray )
{
	if (this != &srcArray)
	{
		if (this->size != 0)
			delete [] this->array;
		this->size = srcArray.getSize();
		this->array = new T[this->size];

		for (unsigned int i = 0; i < this->size; i++)
			this->array[i] = srcArray[i];
	}
	return (*this);
}

template <class T>
T	&Array<T>::operator[]( unsigned int pos ) const
{
	if (pos >= this->size)
		throw	std::out_of_range("The value is out of the range");
	return (this->array[pos]);
}

template <class T>
unsigned int	Array<T>::getSize( void ) const
{
	return (this->size);
}
