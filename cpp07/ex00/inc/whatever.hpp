/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:08:44 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 09:39:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

template <typename M>
M	max( M &a, M &b ) {
	return ( a > b ? a:b );
}

template <typename M>
M	min( M &a, M &b ) {
	return ( a < b ? a:b);
}

template <typename S>
void	swap( S &a, S &b ) 
{
	S	temp;

	temp = a;
	a = b;
	b = temp;
}

#endif