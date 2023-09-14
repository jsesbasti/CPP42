/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:23 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 16:13:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal {
private:
	std::string type;

public:
	Cat( void );
	Cat( const Cat &src );
	~Cat( void );
	
	Cat&	operator=( const Cat &src );

	void	makeSound( void ) const;
};

#endif