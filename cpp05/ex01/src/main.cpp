/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:36:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/12 21:19:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define INCREMENT 0
#define DECREMENT 1
#define GET_NAME 0
#define GET_SIGN_GRADE 1
#define GET_EXEC_GRADE 2
#define GET_IS_SIGNED 3



Bureaucrat	testConstructorBureaucratGrade( unsigned int grade, int& catched )
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

Form	testConstructorFormGrade( unsigned int signGrade, unsigned int execGrade, int& catched )
{
	Form	Default( "Unnamed Form", MIN_GRADE, MIN_GRADE );

	catched = 0;
	try
	{
		Form	form( "Juan's Form", signGrade, execGrade );
		return ( form );
	}
	catch ( std::out_of_range& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
		catched = 1;
	}
	return ( Default );
}

void	doFormConstructorTest( unsigned int testNumber, std::string testName, \
								unsigned int signGrade, unsigned int execGrade )
{
	int	catched;

	std::cout << "Test " << testNumber << ": " << testName << " in constructor: Form\t" \
		<< "Juan( \"Juan's Form\", " << signGrade <<  ", "<< execGrade << " )"  << std::endl;
	testConstructorFormGrade( signGrade, execGrade, catched );
	std::cout << "End of test\n"  << std::endl;
}

void	doFormGetterTest( unsigned int testNumber, std::string testName, \
								Form form, unsigned int mode )
{
	std::cout << "Test " << testNumber << ": " << testName << " in constructor: Form\t" \
		<< "form( \"Juan's Form\", " << MID_GRADE <<  ", " << MIN_GRADE << " )"  << std::endl;
	switch ( mode )
	{
		case GET_NAME:
			std::cout << "form.getName() = " << form.getName() << std::endl;
			break;
		case GET_SIGN_GRADE:
			std::cout << "form.getGradeToSign() = " << form.getGradeToSign() << std::endl;
			break;
		case GET_EXEC_GRADE:
			std::cout << "form.getGradeToExe() = " << form.getGradeToExecute() << std::endl;
			break;
		case GET_IS_SIGNED:
			std::cout << "form.getFormSigned() = " << (form.getSign() ? "true" : "false") << std::endl;
			break;
		default:
			std::cout << "Invalid getter mode" << std::endl;
			break;
	}
	std::cout << "End of test\n"  << std::endl;
}

void	doBureaucratSignFormTest( unsigned int testNumber, std::string testName, \
								Bureaucrat& Juan, Form& form )
{
	std::cout << "Test " << testNumber << ": " << testName << " in signForm method: Form\t" \
		<< "form( \"" << form.getName() << "\", " << form.getGradeToSign() \
		<<  ", "<< form.getGradeToExecute() << ")" << " && Bureaucrat\tJuan( \" " \
		<< Juan.getName() << "\", " << Juan.getGrade() << " )" << " )"  << std::endl;
	std::cout << "\tform stats -> " << form << std::endl;
	std::cout << "\t";
	Juan.signForm( form );
	std::cout << "\tform stats -> " << form << std::endl;
	std::cout << "End of test\n"  << std::endl;
}

// TESTS
void	testsFormConstructor( void )
{
	//Constructor Tests
	
	//	signGrade: Out of range Grades in Form constructor

	doFormConstructorTest( 1, "too low signGrade", MIN_GRADE + 1, MID_GRADE );
	doFormConstructorTest( 2, "too high signGrade", MAX_GRADE - 1, MID_GRADE );
	
	//	execGrade: Out of range Grades in Form constructor

	doFormConstructorTest( 3, "too low execGrade", MID_GRADE, MIN_GRADE + 1 );
	doFormConstructorTest( 4, "too high execGrade", MID_GRADE, MAX_GRADE - 1 );
	
	//	Both: Out of range Grades in Form constructor

	doFormConstructorTest( 5, "too low both signGrade and execGrade", \
							MIN_GRADE + 1, MIN_GRADE + 1 );
	doFormConstructorTest( 6, "too high both signGrade and execGrade", \
							MAX_GRADE - 1, MAX_GRADE - 1 );
	doFormConstructorTest( 7, "too high signGrade and too low execGrade", \
							MAX_GRADE - 1, MIN_GRADE + 1  );
	doFormConstructorTest( 8, "too low signGrade and too high execGrade", \
							MIN_GRADE + 1, MAX_GRADE - 1  );
}

void	testsFormGetters( void )
{
	Form	form( "Juan's Form", MID_GRADE, MIN_GRADE );
	Bureaucrat	Juan( "Juan", MID_GRADE );

	//Getters Tests
	
	//	getName()

	doFormGetterTest( 1, "getName()", form, GET_NAME );

	//	getGradeToSign()

	doFormGetterTest( 2, "getGradeToSign()", form, GET_SIGN_GRADE );

	//	getGradeToExe()

	doFormGetterTest( 3, "getGradeToExe()", form, GET_EXEC_GRADE );

	//	getFormSigned(): Before singed

	doFormGetterTest( 4, "getFormSigned() [ Before Sign a Form ]", form, GET_IS_SIGNED );

	//	getFormSigned(): After singed

	Juan.signForm( form );
	doFormGetterTest( 5, "getFormSigned() [ After Sign a Form ]", form, GET_IS_SIGNED );
}


void	testsBureaucratSignForm( void )
{
	Form		formMinGrade( "Juan's form", MIN_GRADE, MIN_GRADE );
	Form		formMidGrade( "Juan's form", MID_GRADE, MID_GRADE );
	Form		formMaxGrade( "Juan's form", MAX_GRADE, MAX_GRADE );
	Bureaucrat	JuanMinGrade( "Juan", MIN_GRADE );
	Bureaucrat	JuanMidGrade( "Juan", MID_GRADE );
	Bureaucrat	JuanMaxGrade( "Juan", MAX_GRADE );

	//Method Tests
	
	//	Invalid Grade to signForm

	doBureaucratSignFormTest( 1, "too low signGrade", JuanMinGrade, formMidGrade );

	// Limits Grade to signForm and equal grade
	doBureaucratSignFormTest( 4, "signGrade equals to Bureaucrat Grade [ MIN GRADE ]", \
								JuanMinGrade, formMinGrade );
	doBureaucratSignFormTest( 2, "signGrade equals to Bureaucrat Grade [ MID GRADE ]", \
								JuanMidGrade, formMidGrade );
	doBureaucratSignFormTest( 3, "signGrade equals to Bureaucrat Grade [ MAX GRADE ]", \
								JuanMaxGrade, formMaxGrade );

	// Form already signed and their priorities
	doBureaucratSignFormTest( 5, "form is already signed and valid grade", \
								JuanMidGrade, formMidGrade );
	doBureaucratSignFormTest( 6, "form is already signed and invalid grade", \
								JuanMinGrade, formMidGrade );
}

bool	executionQuestion( std::string testsName )
{
	std::string	answer;

	std::cout << "Do you want to execute the " << testsName << " tests [ y / n ]: ";
	std::getline( std::cin, answer );
	if ( answer.compare( "Y" ) == 0 || answer.compare( "y" ) == 0 )
	{
		std::cout << std::endl;
		return ( true );
	}
	return ( false );
}

int	main( void )
{
	std::cout << std::unitbuf;
	if ( executionQuestion( "Form constructor" ) == true )
		testsFormConstructor();
	std::cout << std::endl;

	if ( executionQuestion( "Form getters" ) == true )
		testsFormGetters();
	std::cout << std::endl;

	if ( executionQuestion( "Bureaucrat signForm() method" ) == true )
		testsBureaucratSignForm();
	std::cout << std::endl;

	return ( 0 );
}

// MAIN FROM ERALONSO
// https://github.com/eralonso