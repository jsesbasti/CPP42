/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:26:55 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 08:05:02 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# define MAX_IDEAS 100

# include <iostream>

class Brain
{
private:
	std::string		ideas[MAX_IDEAS];
	unsigned int	idx;
public:
	Brain( void );
	Brain( std::string idea );
	Brain( const Brain &src );
	~Brain( void );

	Brain& operator=( const Brain &src );	
	
	void			b_addIdea( std::string idea );
	std::string		b_getIdea( unsigned int _idx ) const;
	std::string		b_getCurrentIdea( void ) const;
	unsigned int	b_getIndex( void ) const;
};

#endif