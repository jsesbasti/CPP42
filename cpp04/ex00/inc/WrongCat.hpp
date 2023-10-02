/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:08:24 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 16:13:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
	std::string type;
public:
	WrongCat( void );
	WrongCat( const WrongCat &src );
	~WrongCat( void );
	
	WrongCat& operator=( const WrongCat &src );

	void	makeSound( void ) const;
};

#endif