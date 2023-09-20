/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:01:48 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 06:05:10 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice &src );
	~Ice( void );

	Ice& operator=( const Ice &src );

	AMateria*	clone( void ) const;
	void	use( ICharacter& target );
	
};

#endif