/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 22:09:51 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ClapTrap_HPP__
# define __ClapTrap_HPP__

# include <iostream>

class ClapTrap {
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

public:
	ClapTrap( std::string _name );
	~ClapTrap();
	void	attack( const std::string& target);
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif