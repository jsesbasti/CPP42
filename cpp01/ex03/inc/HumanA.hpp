/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:44:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:23:15 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
# define __HUMANA_H__

# include "Weapon.hpp"

class HumanA {

private :
	std::string	name;
	Weapon *weapon;
public :
	HumanA();
	HumanA( std::string _name, Weapon &_weapon );
	~HumanA();
	void	attack();
};

#endif