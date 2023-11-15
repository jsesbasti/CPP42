/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:52:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:40:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void )
{
	this->name = "B3A42";
	this->isSigned = false;
	this->gradeToSign = 1;
	this->gradeToExecute = 1;
	return ;
}

AForm::~AForm( void )
{
	return ;
}

AForm::AForm( std::string _name, unsigned int _gradeToSign, unsigned int _gradeToExecute )
{
	this->name = _name;
	this->isSigned = false;
	this->gradeToSign = _gradeToSign;
	this->gradeToExecute = _gradeToExecute;
	this->checkGradeToSign();
	this->checkGradeToExecute();
}

AForm::AForm( const AForm &form ) : name(form.getName())
{
	this->isSigned = form.getSign();
	this->gradeToSign = form.getGradeToSign();
	this->gradeToExecute = form.getGradeToExecute();
}

AForm::GradeTooLowExeption::GradeTooLowExeption( std::string error ) : std::out_of_range(error)
{
	return ;
}

AForm::GradeTooHighExeption::GradeTooHighExeption( std::string error ) : std::out_of_range(error)
{
	return ;
}

AForm::NotSignedExeption::NotSignedExeption( std::string error ) : std::logic_error(error)
{
	return ;
}

AForm	&AForm::operator=( const AForm &form )
{
	if (this != &form)
	{
		this->name = form.getName();
		this->isSigned = form.getSign();
		this->gradeToSign = form.getGradeToSign();
		this->gradeToExecute = form.getGradeToExecute();
	}
	return (*this);
}

std::string	AForm::getName( void ) const
{
	return (this->name);
}

bool		AForm::getSign( void ) const
{
	return (this->isSigned);
}

unsigned int	AForm::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

unsigned int	AForm::getGradeToExecute( void ) const
{
	return (this->gradeToExecute);
}

void	AForm::checkGradeToSign( void ) const
{
	if (this->gradeToSign < 1)
		throw AForm::GradeTooHighExeption("The grade is too high");
	else if (this->gradeToSign > 150)
		throw AForm::GradeTooLowExeption("The grade is too low");
}

void	AForm::checkGradeToExecute( void ) const
{
	if (this->gradeToExecute < 1)
		throw AForm::GradeTooHighExeption("The grade is too high");
	else if (this->gradeToExecute> 150)
		throw AForm::GradeTooLowExeption("The grade is too low");
}

void	AForm::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowExeption("The grade of the signer is too low");
	this->isSigned = true;
}

void	AForm::execute( const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowExeption("The grade of the executor is too low");
	if (this->isSigned == false)
		throw AForm::NotSignedExeption("The form is not signed");
	executeForm();
}

std::ostream&	operator<<( std::ostream& out, const AForm& form )
{
	out << "Form name: " << form.getName() << ", Form sign grade: " \
		<< form.getGradeToSign() << ", Form exec grade: " \
		<< form.getGradeToExecute() << ", Form is signed: " \
		<< (form.getSign() ? "true" : "false");
	return ( out );
}

