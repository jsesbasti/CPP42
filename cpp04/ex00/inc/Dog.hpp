/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:23 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 09:07:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal {
private:
	std::string type;

public:
	Dog();
	Dog( const Dog &src );
	~Dog();
	
	Dog&	operator=( const Dog &src );

	void	makeSound() const;
};

#endif