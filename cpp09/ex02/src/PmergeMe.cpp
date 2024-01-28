/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:36:37 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/25 15:29:19 by jsebasti         ###   ########.fr       */
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

void	PmergeMe::orderPairs(std::vector<int> &tmp)
{
	int len = tmp.size();
	int last = 0;

	for (int j = 2; j < len; j += 2)
	{
		if (last != j && tmp[last] > tmp[j])
		{
			int auxMin = tmp[j];
			int auxMax = tmp[j + 1];
			tmp[j] = tmp[last];
			tmp[j + 1] = tmp[last + 1];
			tmp[last] = auxMin;
			tmp[last + 1] = auxMax;
		}
		last += j;
	}
}

void	PmergeMe::createA(std::vector<int> &v, std::vector<int> &A)
{
	int len = v.size();
	int pairs = len / 2;
	int i = 0;

	for (int j = 1; j < pairs; j++)
	{
		A.push_back(v[i]);
		i += 2;
	}
	len = A.size();
	v.erase(v.begin());
	while ((int)v.size() > len + 1)
		v.erase(v.begin() + 1);
}

void	PmergeMe::checkOrderInPairs(std::vector<int> &tmp)
{
	int len = tmp.size();
	int pair = len / 2;
	int i = 0;

	for (int j = 1; j < pair; j++)
		i += 2;
	if (tmp[i] > tmp[i + 1])
	{
		int aux = tmp[i];
		tmp[i] = tmp[i + 1];
		tmp[i + 1] = aux;
	}
}

std::vector<int>	PmergeMe::createPairs( std::vector<int> &vectorOrder ) {
	int len = vectorOrder.size();
	int	pairs = len / 2;
	std::vector<int> tmp;

	for (int i = 0; i < pairs; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tmp.push_back(vectorOrder[j]);
		}
		for (int j = 0; j < 2; j++)
			vectorOrder.erase(vectorOrder.begin());
		checkOrderInPairs(tmp);
	}
	return (tmp);
}

void	pushSInA(std::vector<int> &A, std::vector<int> &S)
{
	int last, next;
	for(int i = 0; i < (int)S.size(); i++)
	{
		for (j = 0; j < (int)A.size(); j++)
		{

		}
	}
}

void	PmergeMe::sortVector( std::vector<int> &vectorOrder ) {
	bool	odd = vectorOrder.size() % 2 != 0;
	int	straggler;
	std::vector<int> A;
	std::vector<int> S;

	if (odd == true)
	{
		straggler = vectorOrder[vectorOrder.size() - 1];
		vectorOrder.pop_back();
	}
	std::vector<int> split_vector = createPairs(vectorOrder);
	for (int i = 0; i < (int)split_vector.size(); i++)
	{
		vectorOrder.push_back(split_vector[i]);
	}
	orderPairs(vectorOrder);
	createA(vectorOrder, A);
	S = vectorOrder;
	if (odd == true)
		S.push_back(straggler);
	pushSInA(A, S);
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
	for (int i = 0; i < (int)vectorOrder.size(); i++)
		std::cout << " " << vectorOrder[i];
	std::cout << std::endl;
	std::cout << std::fixed;

	std::cout << "Time to process a range of " << vectorOrder.size() << " elements with std::vector<int> : " << totalTimeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << dequeOrder.size() << " elements with std::deque<int> : " << totalTimeDeque << " us" <<  std::endl;
}