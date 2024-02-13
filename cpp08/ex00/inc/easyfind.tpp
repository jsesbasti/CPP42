/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:59:00 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/30 17:01:33 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int	easyfind(const T &container, const int num) {
	typename T::const_iterator it = container.begin();
	while (it != container.end())
	{
		++it;
		if (*it == num)
			return (*it);
	}
	throw std::out_of_range("Can't find the number in the container");
}