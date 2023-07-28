/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:25:27 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 05:06:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <iostream>

class Weapon {
private:
	std::string	type;
public:
	Weapon();
	Weapon( std::string _type );
	~Weapon();
	std::string	getType() const;
	void		setType( std::string _type );
};

#endif