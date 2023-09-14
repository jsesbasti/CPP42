/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:23 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 11:13:52 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal( std::string _type );
	Animal( const Animal &src );
	virtual ~Animal();
	
	Animal& operator=( const Animal &src );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const = 0;
};

#endif