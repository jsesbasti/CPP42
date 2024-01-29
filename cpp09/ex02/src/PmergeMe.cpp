/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:36:37 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/29 17:32:54 by jsebasti         ###   ########.fr       */
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
	sortVector(vectorOrder, 0, vectorOrder.size() - 1);
	clock_t endTimeVector = clock();
	double totalTimeVector = static_cast<double>(endTimeVector - startTimeVector) / CLOCKS_PER_SEC * 1000000.0;
	clock_t startTimeDeque = clock();
	sortDeque(dequeOrder, 0, dequeOrder.size() - 1);
	clock_t endTimeDeque = clock();
	double totalTimeDeque = static_cast<double>(endTimeDeque - startTimeDeque) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "After:";
	for (int i = 0; i < (int)dequeOrder.size(); i++)
		std::cout << " " << dequeOrder[i];
	std::cout << std::endl;
	std::cout << std::fixed;

	std::cout << "Time to process a range of " << vectorOrder.size() << " elements with std::vector<int> : " << totalTimeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << dequeOrder.size() << " elements with std::deque<int> : " << totalTimeDeque << " us" <<  std::endl;
}