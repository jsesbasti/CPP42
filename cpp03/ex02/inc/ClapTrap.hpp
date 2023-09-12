/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 01:34:21 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap( void );
	ClapTrap( std::string _name );
	ClapTrap( const ClapTrap &src );
	ClapTrap& operator=( const ClapTrap &src );
	~ClapTrap();
	void	attack( const std::string& target);
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif