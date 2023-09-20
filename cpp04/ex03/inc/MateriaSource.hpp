/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 05:55:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/19 06:39:20 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_SOURCE_HPP__
# define __MATERIA_SOURCE_HPP__

# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource {
private:
	AMateria*	newMateria[ 4 ];
	int			cIdx;

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &src );
	~MateriaSource( void );

	MateriaSource&	operator=( const MateriaSource & src );
	
	void	learnMateria( AMateria* );
	AMateria*	createMateria( std::string const & type );

};



#endif // __MATERIA_SOURCE_HPP__
