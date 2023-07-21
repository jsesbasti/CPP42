/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:44:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/17 08:54:09 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <iostream>

class Zombie {

private :
	std::string name;

public :
	Zombie();
	~Zombie();
	void	anounce( void );
	void	set_name( std::string _name);
};

Zombie *zombieHorde( int N, std::string name );

#endif