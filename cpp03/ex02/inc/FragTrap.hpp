/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 01:40:02 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap( std::string _name );
	FragTrap( const FragTrap &src );
	FragTrap& operator=( const FragTrap &src );
	~FragTrap();
	void	highFivesGuys( void );
};

#endif