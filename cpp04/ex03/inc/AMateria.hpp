/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:28:28 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 05:53:57 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_HPP__
# define __A_MATERIA_HPP__

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string	type;
	
public:
	AMateria( void );
	AMateria( std::string const &type );
	AMateria( const AMateria &src );
	virtual ~AMateria( void );

	AMateria& operator=( const AMateria &src );

	std::string const & getType( void ) const; //Returns the materia type
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );

};

#endif