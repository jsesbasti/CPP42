/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:36:37 by jsebasti          #+#    #+#             */
/*   Updated: 2024/02/13 18:59:41 by codespace        ###   ########.fr       */
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
			double check = stringToDouble(av[i]);
			if (check > INT_MAX)
				throw std::invalid_argument("Please introduce numbers smaller than the INT_MAX");
			vectorOrder.push_back(stringToInt(av[i]));
			dequeOrder.push_back(stringToInt(av[i]));
		}
		repeatedNumbers(vectorOrder);
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument(e.what());
	}
}

void	PmergeMe::mergeVector( std::vector<int> &vectorOrder, int left, int mid, int right )
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftvectorM(n1);
	std::vector<int> rightvectorM(n2);
	for (int i = 0; i < n1; i++)
		leftvectorM[i] = vectorOrder[left + i];
	for (int j = 0; j < n2; j++)
		rightvectorM[j] = vectorOrder[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (leftvectorM[i] <= rightvectorM[j])
			vectorOrder[k] = leftvectorM[i++];
		else 
			vectorOrder[k] = rightvectorM[j++];
		k++;
	}
	while (i < n1)
		vectorOrder[k++] = leftvectorM[i++];
	while (j < n2)
		vectorOrder[k] = rightvectorM[j++];
}

void	PmergeMe::sortVector( std::vector<int> &vectorOrder, int left, int right ) {
	if (left < right)
	{
		if (right - left < INSERTAUX)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = vectorOrder[i];
				int j = i - 1;
				while (j >= left && vectorOrder[j] > key)
				{
					vectorOrder[j + 1] = vectorOrder[j];
					j--;
				}
				vectorOrder[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			sortVector(vectorOrder, left, mid);
			sortVector(vectorOrder, mid + 1, right);
			mergeVector(vectorOrder, left, mid, right);
		}
	}
}

void	PmergeMe::mergeDeque( std::deque<int> &dequeOrder, int left, int mid, int right )
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> leftDequeM(n1);
	std::deque<int> rightDequeM(n2);
	for (int i = 0; i < n1; i++)
		leftDequeM[i] = dequeOrder[left + i];
	for (int j = 0; j < n2; j++)
		rightDequeM[j] = dequeOrder[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (leftDequeM[i] <= rightDequeM[j])
			dequeOrder[k] = leftDequeM[i++];
		else 
			dequeOrder[k] = rightDequeM[j++];
		k++;
	}
	while (i < n1)
		dequeOrder[k++] = leftDequeM[i++];
	while (j < n2)
		dequeOrder[k] = rightDequeM[j++];
}

void	PmergeMe::sortDeque( std::deque<int> &dequeOrder, int left, int right ) {
	if (left < right)
	{
		if (right - left < INSERTAUX)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = dequeOrder[i];
				int j = i - 1;
				while (j >= left && dequeOrder[j] > key)
				{
					dequeOrder[j + 1] = dequeOrder[j];
					j--;
				}
				dequeOrder[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			sortDeque(dequeOrder, left, mid);
			sortDeque(dequeOrder, mid + 1, right);
			mergeDeque(dequeOrder, left, mid, right);
		}
	}
}

void	PmergeMe::order( std::string *av, int ac ) {
	std::vector<int>	vectorOrder;
	std::deque<int>		dequeOrder;
	std::clock_t		vecTime[2];
	std::clock_t		dqueTime[2];

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
	vecTime[ 0 ] = std::clock();
	sortVector( vectorOrder, 0, vectorOrder.size() - 1 );
	vecTime[ 1 ] = std::clock();
	dqueTime[ 0 ] = std::clock();
	sortDeque( dequeOrder, 0, dequeOrder.size() - 1 );
	dqueTime[ 1 ] = std::clock();
	std::cout << "After:";
	for (int i = 0; i < (int)dequeOrder.size(); i++)
		std::cout << " " << dequeOrder[i];
	std::cout << std::endl;
	std::cout << std::fixed;

	printTime( vectorOrder.size(), "vector", ( static_cast< double >( vecTime[ 1 ] - vecTime[ 0 ] ) * 1000 ) / CLOCKS_PER_SEC );
	printTime( dequeOrder.size(), "deque", ( static_cast< double >( dqueTime[ 1 ] - dqueTime[ 0 ] ) * 1000 ) / CLOCKS_PER_SEC );
}

int stringToInt(const std::string& str) {
    const char* cStr = str.c_str();
    char* endptr;
    int result = std::strtol(cStr, &endptr, 10);
    if (*endptr != '\0' && !std::isspace(*endptr)) {
        result = 0;
    }
    return result;
}

double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}

void	PmergeMe::printTime( int range, std::string container, double timeDiff )
{
	std::cout << std::fixed;
	std::cout << "Time to process a range of " << range;
	std::cout << " elements with std::" << container;
	std::cout << " : " << timeDiff << " us" << std::endl;
}
