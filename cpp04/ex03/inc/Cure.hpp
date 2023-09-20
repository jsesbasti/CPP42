/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:20 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 06:05:04 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure &src );
	~Cure( void );

	Cure& operator=( const Cure &src );

	AMateria*	clone( void ) const;
	void	use( ICharacter& target );
	
};

#endif