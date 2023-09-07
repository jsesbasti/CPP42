/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:41:46 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 19:20:15 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs( Fixed val ) {
	if (val < 0)
		return (val * -1);
	return (val);
}

static Fixed	area(Point const a, Point const b, Point const c) {
	return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
			 ( b.getX() * ( c.getY() - a.getY() ) ) +
			 ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abcarea = abs(area(a, b, c));
	Fixed	pabarea = abs(area(point, b, c));
	Fixed	pbcarea = abs(area(point, b, c));
	Fixed	pcaarea = abs(area(point, c, a));

	return (abcarea > pabarea + pbcarea + pcaarea);
}