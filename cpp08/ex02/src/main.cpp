/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:33:48 by eralonso          #+#    #+#             */
/*   Updated: 2023/12/14 21:59:40 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

void	listImplementation( void )
{
	std::list< int >	lst;
	unsigned int		n;

	std::cout << "Adding numbers [ 2 ] -> 5, 17" << std::endl;
	lst.push_back( 5 );
	lst.push_back( 17 );

	std::cout << "\nTop element of lst: " << lst.back() << std::endl;
	std::cout << "lst size: " << lst.size() << std::endl;

	std::cout << "\nPop back element of lst" << std::endl;
	lst.pop_back();

	std::cout << "\nTop element of lst: " << lst.back() << std::endl;
	std::cout << "lst size: " << lst.size() << std::endl;

	std::cout << "\nAdding numbers [ 4 ] -> 3, 5, 737, 0" << std::endl;
	lst.push_back( 3 );
	lst.push_back( 5 );
	lst.push_back( 737 );
	lst.push_back( 0 );

	std::cout << "\nTop element of lst: " << lst.back() << std::endl;
	std::cout << "lst size: " << lst.size() << "\n" << std::endl;

	std::list< int >::iterator it = lst.begin();
	std::list< int >::iterator ite = lst.end();
	++it;
	--it;
	n = 0;
	while ( it != ite )
	{
		std::cout << "lst [ " << n << " ]: " << *it << std::endl;
		++it;
		n++;
	}


	std::cout << "\n\nCopy lst to lst2 with copy constructor" << std::endl;
	std::list< int >	lst2( lst );

	std::cout << "\nTop element of lst2: " << lst2.back() << std::endl;
	std::cout << "lst2 size: " << lst2.size() << std::endl;

	std::cout << "\nPop back element of lst2" << std::endl;
	lst2.pop_back();

	std::cout << "\nTop element of lst2: " << lst2.back() << std::endl;
	std::cout << "lst2 size: " << lst2.size() << std::endl;


	std::cout << "\n\nCopy lst to lst3 with assignment operator" << std::endl;
	std::list< int >	lst3;
	lst3 = lst;

	std::cout << "\nTop element of lst3: " << lst3.back() << std::endl;
	std::cout << "lst2 size: " << lst3.size() << std::endl;

	std::cout << "\nPop back element of lst3" << std::endl;
	lst3.pop_back();

	std::cout << "\nTop element of lst3: " << lst3.back() << std::endl;
	std::cout << "lst3 size: " << lst3.size() << std::endl;
}

int main( void )
{
	MutantStack< int >	mstack;
	unsigned int		n;

	std::cout << "\n\n[ MutantStack implementation ]\n" << std::endl;
	std::cout << "Adding numbers [ 2 ] -> 5, 17" << std::endl;
	mstack.push( 5 );
	mstack.push( 17 );

	std::cout << "\nTop element of MutantStack: " << mstack.top() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

	std::cout << "\nPop top element of MutantStack" << std::endl;
	mstack.pop();

	std::cout << "\nTop element of MutantStack: " << mstack.top() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

	std::cout << "\nAdding numbers [ 4 ] -> 3, 5, 737, 0" << std::endl;
	mstack.push( 3 );
	mstack.push( 5 );
	mstack.push( 737 );
	mstack.push( 0 );

	std::cout << "\nTop element of MutantStack: " << mstack.top() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << "\n" << std::endl;

	MutantStack< int >::iterator it = mstack.begin();
	MutantStack< int >::iterator ite = mstack.end();
	++it;
	--it;
	n = 0;
	while ( it != ite )
	{
		std::cout << "MutantStack [ " << n << " ]: " << *it << std::endl;
		++it;
		n++;
	}

	std::cout << "\n\nCopy MutantStack to Stack with copy constructor" << std::endl;
	std::stack< int >	s( mstack );

	std::cout << "\nTop element of stack: " << s.top() << std::endl;
	std::cout << "stack size: " << s.size() << std::endl;

	std::cout << "\nPop top element of MutantStack" << std::endl;
	s.pop();

	std::cout << "\nTop element of Stack: " << s.top() << std::endl;
	std::cout << "Stack size: " << s.size() << std::endl;


	std::cout << "\n\nCopy MutantStack to Stack with assignment operator" << std::endl;
	std::stack< int >	s2;
	s2 = mstack;

	std::cout << "\nTop element of stack: " << s2.top() << std::endl;
	std::cout << "stack size: " << s2.size() << std::endl;

	std::cout << "\nPop top element of MutantStack" << std::endl;
	s2.pop();

	std::cout << "\nTop element of Stack: " << s2.top() << std::endl;
	std::cout << "Stack size: " << s2.size() << std::endl;

	std::cout << "\n\n[ List implementation ]\n" << std::endl;
	listImplementation();
	return ( 0 );
}