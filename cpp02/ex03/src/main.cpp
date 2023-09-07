/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/07 19:20:05 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(3, 6);
	Point const point(3, 1);
	
	if (bsp(a, b, c, point) == true)
		std::cout << "El punto pertenece al triangulo" << std::endl;
	else
		std::cout << "El punto no pertenece al triangulo" << std::endl;
	return 0;
}