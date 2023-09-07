/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/06 11:00:57 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath> //roundf

class Fixed
{
private:
	int					num;
	static const int	floating = 8;
public:
	Fixed( void );
	Fixed( const int n );
	Fixed( const float n );
	Fixed( const Fixed &fix );
	Fixed& operator =( const Fixed &fix );
	~Fixed();

	int		getRawBits( void ) const ;
	void	setRawBits( int const raw );

	int		toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif