/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:05:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 16:20:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <iostream>

class WrongAnimal {
protected:
	std::string type;
	
public:
	WrongAnimal( void );
	WrongAnimal( std::string _type );
	WrongAnimal( const WrongAnimal &src );
	virtual ~WrongAnimal( void );
	
	WrongAnimal& operator=( const WrongAnimal &src );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;
};

#endif