/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:25:47 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:22:37 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
# define __HUMANB_H__

# include "Weapon.hpp"

class HumanB {

private :
	std::string	name;
	Weapon *weapon;
public :
	HumanB();
	HumanB( std::string _name );
	~HumanB();
	void	attack();
	void	setWeapon( Weapon &_weapon );
};

#endif