/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:08:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/12 07:36:18 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap( void );
	ScavTrap( std::string _name );
	ScavTrap( const ScavTrap &src );
	ScavTrap& operator=( const ScavTrap &src );
	~ScavTrap();
	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif