/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/12/14 22:00:06 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <stack>

template <typename T>
class MutantStack : public std::stack< T >
{
public:
	MutantStack( void );
	MutantStack( const MutantStack & srcMTS );
	~MutantStack( void );

	MutantStack&			operator=( const MutantStack & srcMTS );

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator 		begin( void );
	iterator		end( void );
};

# include "MutantStack.tpp"

#endif