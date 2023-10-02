/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:44:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/02 11:14:42 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "ICharacter.hpp"
# include <iostream>

# define MAX_INVENTORY 4

class Character : public ICharacter {
private:
	std::string name;
	AMateria*	inventory[4];
	AMateria**	floor;
	int			currentIdx;
	int			flooridx;

public:
	Character( void );
	Character( std::string _name );
	Character( const Character& src);
	~Character( void );

	Character& operator=( const Character& src );
	
	std::string const&		getName( void ) const;

	void					use(int idx, ICharacter& target );
	void					equip(AMateria* m);
	void					unequip(int idx);
	void					addFloor( AMateria &m );
	void					printFloor( void ) const;
	void					printMaterias( void ) const;
	bool					existMateriaInFloor( AMateria& m );
};

AMateria				**incrementFloorMem( AMateria **floor, int floorLen );
AMateria				**copyFloor( AMateria **srcFloor, int newFloorLen );

#endif