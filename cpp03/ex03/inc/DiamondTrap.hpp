/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:56:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 01:07:39 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

public:
	DiamondTrap( void );
	DiamondTrap( std::string _name );
	DiamondTrap( const DiamondTrap &src );
	DiamondTrap& operator=( const DiamondTrap &src );
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI( void );	
};

#endif