/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:23 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 11:12:35 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain*		brain;

public:
	Dog( void );
	Dog( const Dog &src );
	~Dog( void );
	
	Dog&			operator=( const Dog &src );

	void			makeSound( void ) const;
	void			addIdea( std::string idea );
	std::string		getIdea( unsigned int idx ) const;
	unsigned int	getIndex( void ) const;
	std::string		getCurrentIdea( void ) const;
};

#endif