/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:08:44 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 11:37:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

template <typename T>
void	iter( T *array, int len, void (*f)(T&) ) {
	if (array)
	{
		for (int i = 0; i < len; i++)
		{
			(*f)(array[i]);
		}
	}
}

#endif