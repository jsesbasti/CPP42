/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:04:17 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/28 20:05:07 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main( int ac, char **av ) {
	if (ac != 4)
	{
		std::cerr << "This program uses 3 params:" << std::endl;
		std::cerr << "\t1-> Original File" << std::endl;
		std::cerr << "\t2-> Text to replace"<< std::endl;
		std::cerr << "\t3-> Text to replace by" << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string	s1 = av[2];
	std::string s2 = av[3];
	std::string temp;

	if (s1.empty() || s2.empty())
	{
		std::cerr << "s1 && s2 need valors" << std::endl;
		return (1);
	}
	file += ".replace";
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "Error opening " << av[1] << std::endl;
		return (1);
	}
	std::ofstream ofs(file);
	if (!ofs.is_open())
	{
		std::cout << "Error opening " << file << std::endl;
		return (1);
	}
	size_t i = 0;
	while (std::getline(ifs, temp))
	{
		while ((i = temp.find(s1, i)) != (size_t) -1)
		{
			temp.erase(i, s1.length());
			temp.insert(i, s2);
			i += s1.length();
		}
		i = 0;
		ofs << temp;
		ofs << std::endl;
	}
	ofs.close();
	ifs.close();
	return (0);
}