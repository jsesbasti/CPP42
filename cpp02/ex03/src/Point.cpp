/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:06:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 14:37:35 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point ( void ) : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Point::Point ( const Point &copy ) : x(copy.x), y(copy.y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::Point ( const float p1, const float p2) : x(p1), y(p2) {
	std::cout << "Points constructor called" << std::endl;
}

Point::~Point ( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Point& Point::operator=( const Point &asg ) {
	if (this != &asg)
	{
		(Fixed)this->x = asg.getX();
		(Fixed)this->y = asg.getY();
	}
	return *this;
}

Fixed	Point::getX( void ) const {
	return (this->x);
}

Fixed	Point::getY( void ) const {
	return (this->y);
}