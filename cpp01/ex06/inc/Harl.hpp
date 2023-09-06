/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:44:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/08/15 19:49:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
# define __HARL_H__

# include <iostream>

class Harl {

private :
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public :
	Harl();
	~Harl();
	void	complain( std::string level );
};

typedef void (Harl::*instance)(void);

#endif