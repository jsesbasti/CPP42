/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:16:06 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/12 11:03:23 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template < typename T >
void	Span::addNumber( const typename T::iterator& start, const typename T::iterator& end ) {
	if ( std::distance( start, end ) + this->vec.size() > this->size  )
		throw std::length_error( "Length is too long" );
	this->vec.insert( start, end );
}