/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:29:42 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/16 09:58:50 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iomanip>
# include <string>
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <chrono>

# define INSERTAUX 3000

class PmergeMe
{
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe( const PmergeMe &srcChain );
	
	PmergeMe	operator=( const PmergeMe &srcChain );

	static void	sortVector( std::vector<int> &vectorOrder );

	static void	stringNumber( std::string num );
	static void	repeatedNumbers( std::vector<int> &vectorOrder );
	static void parse( std::string *av, int ac, std::vector<int> &vectorOrder, std::deque<int> &dequeOrder);

public:
	static void	order( std::string *av, int ac );
};

#endif