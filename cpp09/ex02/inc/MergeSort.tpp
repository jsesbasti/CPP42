/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeSort.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:37:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 18:48:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void	PmergeMe::sort( T &Order, int left, int right ) {
	if (left < right)
	{
		if (right - left < INSERTAUX)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = Order[i];
				int j = i - 1;
				while (j >= left && Order[j] > key)
				{
					Order[j + 1] = Order[j];
					j--;
				}
				Order[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			sort(Order, left, mid);
			sort(Order, mid + 1, right);
			merge(Order, left, mid, right);
		}
	}
}

template <typename T>
void	PmergeMe::merge( T &Order, int left, int mid, int right )
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	T leftM(n1);
	T rightM(n2);
	for (int i = 0; i < n1; i++)
		leftM[i] = Order[left + i];
	for (int j = 0; j < n2; j++)
		rightM[j] = Order[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (leftM[i] <= rightM[j])
			Order[k] = leftM[i++];
		else 
			Order[k] = rightM[j++];
		k++;
	}
	while (i < n1)
		Order[k++] = leftM[i++];
	while (j < n2)
		Order[k] = rightM[j++];
}
