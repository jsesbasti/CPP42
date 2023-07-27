/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/27 00:42:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class Fixed
{
private:
	int					floating;
	static const int	num;
public:
	Fixed( static const	int _num );
	Fixed( Fixed &fix, static const int _num );
	~Fixed();
	int		getRawBits( void );
	void	setRawBits( int const raw );
};

