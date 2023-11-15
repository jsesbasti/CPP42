/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:36:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/12 23:28:50 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define INCREMENT 0
#define DECREMENT 1

Bureaucrat	testConstructorGrade( unsigned int grade, int& catched )
{
	Bureaucrat	Joan( "Juan", MIN_GRADE );

	catched = 0;
	try
	{
		Bureaucrat	Juan( "Juan", grade );
		return ( Juan );
	}
	catch ( std::out_of_range& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
		catched = 1;
	}
	return ( Joan );
}

void	iterGrade( Bureaucrat& Juan, unsigned int n, unsigned int mode )
{
	for ( unsigned int i = 0; i < n; i++ )
	{
		if ( mode == DECREMENT )
		{
			std::cout << "\tDecrement grade by 1" << std::endl;
			Juan.decrementGrade();
		}
		else
		{
			std::cout << "\tIncrement grade by 1" << std::endl;
			Juan.incrementGrade();
		}
	}
}

void	testModifyGrade( unsigned int mode, unsigned int grade, unsigned int n )
{
	int			catched;
	Bureaucrat	Juan;

	catched = 0;
	Juan = testConstructorGrade( grade, catched );
	if ( catched == 1 )
		return ;
	std::cout << "\t[ START ]: Juan stats -> " << Juan << std::endl;
	try
	{
		iterGrade( Juan, n, mode );
	}
	catch ( std::out_of_range& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
	std::cout << "\t[ END ]: Juan stats -> " << Juan << std::endl;
}

int	main( void )
{
	int	catched;

	//Constructor Tests
	
	//	Out of range Grades
	std::cout << "Test too low grade in constructor: Bureaucrat\tJuan( \"Juan\", 151 )"  << std::endl;
	testConstructorGrade( 151, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade in constructor: Bureaucrat\tJuan( \"Juan\", 0 )"  << std::endl;
	testConstructorGrade( 0, catched );
	std::cout << "End of test\n"  << std::endl;
	
	//	Valid Grades
	std::cout << "Test MAX_GRADE (" << MAX_GRADE << ") constructor: Bureaucrat\tJuan( \"Juan\", " << MAX_GRADE << " )"  << std::endl;
	testConstructorGrade( MAX_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test MIN_GRADE (" << MIN_GRADE << ") constructor: Bureaucrat\tJuan( \"Juan\", " << MIN_GRADE << " )"  << std::endl;
	testConstructorGrade( MIN_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test MID_GRADE " << MID_GRADE << " constructor: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testConstructorGrade( MID_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	//Increment/Decrement Methods Tests
	
	//	Out of range Grades Iterations
	std::cout << "Test too low grade with decrement method: Bureaucrat\tJuan( \"Juan\", 150 )"  << std::endl;
	testModifyGrade( DECREMENT, 150, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade with increment method: Bureaucrat\tJuan( \"Juan\", 1 )"  << std::endl;
	testModifyGrade( INCREMENT, 1, 1 );
	std::cout << "End of test\n"  << std::endl;

	//	Valid Grades Iterations
	std::cout << "Test decrement method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( DECREMENT, MID_GRADE, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( INCREMENT, MID_GRADE, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test decrement method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( DECREMENT, MID_GRADE, 10 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( INCREMENT, MID_GRADE, 10 );
	std::cout << "End of test\n"  << std::endl;

	//Getter Methods Tests

	//	getName()
	Bureaucrat	Juan = testConstructorGrade( MID_GRADE, catched );
	std::cout << "Test getName method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	std::cout << "Name: " << Juan.getName() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	//	getGrade()
	std::cout << "Test getGrade method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	std::cout << "Grade: " << Juan.getGrade() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	return ( 0 );
}

// MAIN FROM ERALONSO
// https://github.com/eralonso