/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/14 11:24:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <set>

class Span
{
private:
	unsigned int		size;
	std::multiset<int>	vec;

public:
	Span( void );
	Span( unsigned int _N );
	Span( const Span & srcSpan );
	~Span( void );

	Span&			operator=( const Span & srcSpan );

	void			addNumber( int _N );

	template < typename T >
	void			addNumber( const typename T::iterator& start, const typename T::iterator& end );

	void			fill( unsigned int n );
	void			fill( int start, int end );

	long			shortestSpan( void );
	long			longestSpan( void );

	int				getNumber( unsigned int pos ) const;
	unsigned int	getSize( void ) const;
	unsigned int	getArgs( void ) const;
};

std::ostream&		operator<<( std::ostream& out, const Span& span );

# include "Span.tpp"

#endif