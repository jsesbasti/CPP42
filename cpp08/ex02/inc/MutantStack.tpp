/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:16:06 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/14 21:58:11 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template < typename T >
MutantStack< T >::MutantStack( void ): std::stack< T >()
{
}

template < typename T >
MutantStack< T >::MutantStack( const MutantStack& srcMTS ): std::stack< T >( srcMTS )
{
}

template < typename T >
MutantStack< T >::~MutantStack( void )
{
}

template < typename T >
MutantStack< T >&	MutantStack< T >::operator=( const MutantStack& srcMTS )
{
	return ( std::stack< T >::operator=( srcMTS ) );
}

template < typename T >
typename MutantStack< T >::iterator	MutantStack< T >::begin( void )
{
	return ( this->c.begin() );
}

template < typename T >
typename MutantStack< T >::iterator	MutantStack< T >::end( void )
{
	return ( this->c.end() );
}