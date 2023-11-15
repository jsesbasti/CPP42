/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:36:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:30 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define INCREMENT 0
#define DECREMENT 1
#define GET_NAME 0
#define GET_SIGN_GRADE 1
#define GET_EXEC_GRADE 2
#define GET_IS_SIGNED 3
#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5
#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45
#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

#include <fcntl.h>
#include <unistd.h>

#define C_DEFAULT	"\033[0m"
#define C_RED		"\033[1;91m"
#define C_GREEN		"\033[1;92m"
#define C_YELLOW	"\033[1;93m"
#define C_BLUE		"\033[1;94m"
#define C_PINK		"\033[1;95m"
#define C_CYAN		"\033[1;96m"
#define C_WHITE		"\033[1;97m"
#define C_PURPLE	"\033[1;38;2;150;25;250m"

// Utils
void	doCheckFormGradeTest( unsigned int& testNumber, AForm* form, unsigned int signExpectedValue, unsigned int execExpectedValue )
{
	std::cout << C_BLUE << "Test " << testNumber++ << ": " << C_PINK << "Check sign grade in " << form->getName() << " class: " \
				<< form->getName() << "\tform" << C_WHITE << std::endl;
	std::cout << "\tExpected value: " << signExpectedValue << " | Resultant value: " << form->getGradeToSign() << std::endl;
	std::cout << "End of test\n" << std::endl;
	std::cout << C_BLUE << "Test " << testNumber++ << ": " << C_PINK << "Check exec grade in " << form->getName() << " class: " \
				<< form->getName() << "\tform" << C_WHITE << std::endl;
	std::cout << "\tExpected value: " << execExpectedValue << " | Resultant value: " << form->getGradeToExecute() << std::endl;
	std::cout << C_BLUE << "End of test\n" << C_WHITE << std::endl;
}

void	doExecuteFormTest( unsigned int& testNumber, std::string testName, Bureaucrat Juan, AForm* form )
{
	std::cout << C_BLUE << "Test " << testNumber++ << ": " << C_PINK << "" << testName << " in executeForm method with \"" << form->getName() << "\" form: " \
				<< "Bureaucrat\tJuan( \"" << Juan.getName() << "\", " << Juan.getGrade() << " ) && " << form->getName() << "\tform( \"" \
				<< static_cast<ShrubberyCreationForm *>(form)->getTarget() << "\" )" << C_WHITE << std::endl;
	std::cout << C_GREEN << "[ BEFORE ] " << C_WHITE << "form stats -> " << *static_cast<ShrubberyCreationForm *>(form) << std::endl;
	std::cout << "\t";
	Juan.executeForm( *form );
	std::cout << C_CYAN << "[ AFTER ] " << C_WHITE << " form stats -> " << *static_cast<ShrubberyCreationForm *>(form) << std::endl;
	std::cout << C_BLUE << "End of test\n" << C_WHITE << std::endl;
}

// Tests
void	testsSCFGrades( void )
{
	AForm			*SCForm = new ShrubberyCreationForm;
	AForm			*RRForm = new RobotomyRequestForm;
	AForm			*PPForm = new PresidentialPardonForm;
	unsigned int	testNumber;

	testNumber = 0;

	//Check correct grades for ShrubberyCreationForm

	doCheckFormGradeTest( testNumber, SCForm, SCF_SIGN_GRADE, SCF_EXEC_GRADE );

	//Check correct grades for RobotomyRequestForm

	doCheckFormGradeTest( testNumber, RRForm, RRF_SIGN_GRADE, RRF_EXEC_GRADE );

	//Check correct grades for PresidentialPardonForm

	doCheckFormGradeTest( testNumber, PPForm, PPF_SIGN_GRADE, PPF_EXEC_GRADE );

	//Clean all dynamic allocated memory
	delete SCForm;
	delete RRForm;
	delete PPForm;
}

void	testsBureaucratExecuteForm( void )
{
	AForm			*SCForm = new ShrubberyCreationForm( "testSCF" );
	AForm			*SCFormFile = new ShrubberyCreationForm( "testSCFFail" );
	AForm			*RRForm = new RobotomyRequestForm( "testRRF" );
	AForm			*PPForm = new PresidentialPardonForm( "testPPF" );
	Bureaucrat		JuanMin( "Mini Juan", MIN_GRADE );
	Bureaucrat		JuanMid( "Medium Juan", MID_GRADE );
	Bureaucrat		JuanMax( "Maximun Juan", MAX_GRADE );
	int				invalidFile;
	unsigned int	testNumber;

	testNumber = 0;

	//Check correct execute for ShrubberyCreationForm

	std::cout << C_PURPLE << "\t\t[ TEST ] -> ShrubberyCreationForm\n" << C_WHITE << std::endl;
	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMin, SCForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade to execute", JuanMid, SCForm );
	JuanMid.signForm( *SCForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMin, SCForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMid, SCForm );
	unlink( "testSCFFail_shrubbery" );
	invalidFile = open( "testSCFFail_shrubbery", O_CREAT, 0000 );
	if ( invalidFile == -1 )
	{
		delete SCForm;
		delete SCFormFile;
		delete RRForm;
		delete PPForm;
		std::cerr << "Error while trying to create a \"testSCFFail\" for testing" << std::endl;
		return ;
	}
	JuanMid.signForm( *SCFormFile );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute but invalid file [ Can't write in file ]", JuanMid, SCFormFile );
	close( invalidFile );

	//Check correct execute for RobotomyRequestForm

	std::cout << C_PURPLE << "\t\t[ TEST ] -> RobotomyRequestForm\n" << C_WHITE << std::endl;
	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMid, RRForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade", JuanMax, RRForm );
	JuanMax.signForm( *RRForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMin, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMax, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute [ Special case for Robotomy because output can change ] ", JuanMax, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute [ Special case for Robotomy because output can change ] ", JuanMax, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute [ Special case for Robotomy because output can change ] ", JuanMax, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute [ Special case for Robotomy because output can change ] ", JuanMax, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute [ Special case for Robotomy because output can change ] ", JuanMax, RRForm );

	//Check correct execute for PresidentialPardonForm

	std::cout << C_PURPLE << "\t\t[ TEST ] -> PresidentialPardonForm\n" << C_WHITE << std::endl;
	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMid, PPForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade to execute", JuanMax, PPForm );
	JuanMax.signForm( *PPForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMid, PPForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMax, PPForm );

	//Clean all dynamic allocated memory
	delete SCForm;
	delete SCFormFile;
	delete RRForm;
	delete PPForm;
}

bool	executionQuestion( std::string testsName )
{
	std::string	answer;

	std::cout << C_YELLOW << "Do you want to execute the \"" << testsName << "\" tests [ y / n ]: " << C_WHITE;
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
	if ( executionQuestion( "[ ShrubberyCreationForm / RobotomyRequestForm / PresidentialPardonForm ] sign and exec grades" ) == true )
		testsSCFGrades();
	std::cout << std::endl;

	if ( executionQuestion( "Bureaucrat executeForm && [ ShrubberyCreationForm / RobotomyRequestForm / PresidentialPardonForm ] execute methods" ) == true )
		testsBureaucratExecuteForm();
	std::cout << std::endl;

	return ( 0 );
}

// MAIN FROM ERALONSO
// https://github.com/eralonso