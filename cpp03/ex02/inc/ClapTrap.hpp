/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 19:09:59 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	int				hit_points;
	int				energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap( void );
	ClapTrap( std::string _name );
	ClapTrap( const ClapTrap &src );
	ClapTrap& operator=( const ClapTrap &src );
	virtual ~ClapTrap();

	void	attack( const std::string& target);
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	std::string	getName( void ) const;
	int			getHitPoints( void ) const;
	int			getEnergyPoints( void ) const;
	int			getAttackDamage( void ) const;

	void	setName( std::string _name );
	void	setHitPoints( int _hit_points );
	void	setEnergyPoints( int _energy_points );
	void	setAttackDamage( unsigned int _attack_damage );
};

#endif