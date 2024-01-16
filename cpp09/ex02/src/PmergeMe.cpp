/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:36:37 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/16 14:25:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {

}

PmergeMe::PmergeMe( const PmergeMe &srcChain ) {
	(void)srcChain;
}

PmergeMe	PmergeMe::operator=( const PmergeMe &srcChain ) {
	(void)srcChain;
	return (*this);
}

PmergeMe::~PmergeMe( void ) {

}

void	PmergeMe::stringNumber( std::string num )
{
	if (num.empty())
		throw std::invalid_argument("Please introduce only positve numbers");
	for (int i = 0; i < (int)num.length(); i++)
	{
		if (!std::isdigit(num[i]))
		{
			throw std::invalid_argument("Please introduce only positve numbers");
			return ;
		}
	}
}

void	PmergeMe::repeatedNumbers( std::vector<int> &vectorOrder )
{
	for (int i = 0; i < (int)vectorOrder.size(); i++)
	{
		for (int j = 0; j < (int)vectorOrder.size(); j++)
		{
			if (j == i)
				continue ;
			if (vectorOrder[i] == vectorOrder[j])
				throw std::invalid_argument("Repeated numbers found");
		}
	}
}

void	PmergeMe::parse( std::string *av, int ac, std::vector<int> &vectorOrder, std::deque<int> &dequeOrder)
{
	try
	{
		for (int i = 0; i < ac; i++)
		{
			stringNumber(av[i]);
			double check = std::stod(av[i]);
			if (check > INT_MAX)
				throw std::invalid_argument("Please introduce numbers smaller than the INT_MAX");
			vectorOrder.push_back(std::stoi(av[i]));
			dequeOrder.push_back(std::stoi(av[i]));
		}
		repeatedNumbers(vectorOrder);
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument(e.what());
	}
}

void	PmergeMe::createPairs( std::vector<int> &vectorOrder, bool odd ) {
	int len = vectorOrder.size();

	if (odd == true)
		len -= 1;
	for (int i = 0; i < len; i++)
	{

	}
}

void	PmergeMe::sortVector( std::vector<int> &vectorOrder ) {
	bool	odd = true;
	int		last;

	if (vectorOrder.size() % 2 == 0)
	{
		odd = false;
		last = vectorOrder[vectorOrder.size()];
	}
	std::unordered_set<int, int> pairs = createPairs(vectorOrder, odd);

}

void	PmergeMe::order( std::string *av, int ac ) {
	std::vector<int>	vectorOrder;
	std::deque<int>		dequeOrder;

	try
	{
		parse(av, ac, vectorOrder, dequeOrder);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
	std::cout << "Before:";
	for (int i = 0; i < ac; i++)
		std::cout << " " << vectorOrder[i];
	std::cout << std::endl;
	clock_t	startTimeVector = clock();
	sortVector( vectorOrder);
	clock_t endTimeVector = clock();
	clock_t startTimeDeque = clock();
	// sortDeque( dequeOrder, 0, dequeOrder.size() - 1);
	clock_t endTimeDeque = clock();
	double totalTimeVector = static_cast<double>(endTimeVector - startTimeVector) / CLOCKS_PER_SEC * 1000000.0;
	double totalTimeDeque = static_cast<double>(endTimeDeque - startTimeDeque) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "After:";
	for (int i = 0; i < ac; i++)
		std::cout << " " << dequeOrder[i];
	std::cout << std::endl;
	std::cout << std::fixed;

	std::cout << "Time to process a range of " << vectorOrder.size() << " elements with std::vector<int> : " << totalTimeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << dequeOrder.size() << " elements with std::deque<int> : " << totalTimeDeque << " us" <<  std::endl;
}