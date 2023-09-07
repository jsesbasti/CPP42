/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 14:01:28 by jsebasti         ###   ########.fr       */
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
	Fixed( void ); //default constructor
	Fixed( const int n ); //Int constructor
	Fixed( const float n ); //float constructor
	Fixed( const Fixed &fix ); //copy constructor
	Fixed&	operator=( const Fixed &fix ); //operator= overload
	// ------ Arithmetics --------
	Fixed	operator+( const Fixed &fix ) const;
	Fixed	operator-( const Fixed &fix ) const;
	Fixed	operator*( const Fixed &fix ) const;
	Fixed	operator/( const Fixed &fix ) const;

	// ------ Comparision --------
	bool	operator>( const Fixed &fix ) const;
	bool	operator<( const Fixed &fix ) const;
	bool	operator>=( const Fixed &fix ) const;
	bool	operator<=( const Fixed &fix ) const;
	bool	operator!=( const Fixed &fix ) const;
	bool	operator==( const Fixed &fix ) const;

	// ------ Increment/Decrement -------
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	// ------ Max & Min -----------
	static Fixed&	min( Fixed &a, Fixed &b );
	static const Fixed&	min( const Fixed &a, const Fixed &b );
	static Fixed&	max( Fixed &a, Fixed &b );
	static const Fixed&	max( const Fixed &a, const Fixed &b );

	~Fixed(); //Destructor

	int		getRawBits( void ) const ;
	void	setRawBits( int const raw );

	int		toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif