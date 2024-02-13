/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:29:42 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/29 17:29:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iostream>
# include <sstream>
# include <algorithm>
# include <string>
# include <iomanip>
# include <vector>
# include <deque>
# include <climits>
# include <ctime>

# define INSERTAUX 3000

class PmergeMe
{
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe( const PmergeMe &srcChain );
	
	PmergeMe	operator=( const PmergeMe &srcChain );

	static void				sortVector( std::vector<int> &vectorOrder, int left, int right );
	static void				mergeVector( std::vector<int> &vectorOrder, int left, int mid, int right );

	static void				sortDeque( std::deque<int> &dequeOrder, int left, int right );
	static void				mergeDeque( std::deque<int> &dequeOrder, int left, int mid, int right );

	static void				stringNumber( std::string num );
	static void				repeatedNumbers( std::vector<int> &vectorOrder );
	static void 			parse( std::string *av, int ac, std::vector<int> &vectorOrder, std::deque<int> &dequeOrder);

public:
	static void				order( std::string *av, int ac );
};

int		stringToInt(const std::string& str);
double	stringToDouble(const std::string& str);

#endif