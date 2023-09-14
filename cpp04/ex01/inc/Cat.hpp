/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:23 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 07:41:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	std::string type;
	Brain*		brain;

public:
	Cat( void );
	Cat( const Cat &src );
	~Cat( void );
	
	Cat&			operator=( const Cat &src );

	void			makeSound( void ) const;
	void			addIdea( std::string idea );
	std::string		getIdea( unsigned int idx ) const;
	unsigned int	getIndex( void ) const;
	std::string		getCurrentIdea( void ) const;
};

#endif