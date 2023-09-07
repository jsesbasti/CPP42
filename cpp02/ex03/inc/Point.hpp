/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:01:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 19:09:35 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point {
private:
	Fixed const	x;
	Fixed const	y;

public:
	Point( void );
	Point( const Point &copy );
	Point( const float p1, const float p2);
	Point& operator=( const Point &asg );
	~Point();

	//getters
	Fixed getX( void ) const;
	Fixed getY( void ) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif