/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:52:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/12 21:28:58 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void )
{
	this->name = "B3A42";
	this->isSigned = false;
	this->gradeToSign = 1;
	this->gradeToExecute = 1;
	return ;
}

Form::~Form( void )
{
	return ;
}

Form::Form( std::string _name, unsigned int _gradeToSign, unsigned int _gradeToExecute )
{
	this->name = _name;
	this->isSigned = false;
	this->checkGradeToSign(_gradeToSign);
	this->checkGradeToExecute(_gradeToExecute);
}

Form::Form( const Form &form ) : name(form.getName())
{
	this->isSigned = form.getSign();
	this->gradeToSign = form.getGradeToSign();
	this->gradeToExecute = form.getGradeToExecute();
}

Form::GradeTooLowExeption::GradeTooLowExeption( std::string error ) : std::out_of_range(error)
{
	return ;
}

Form::GradeTooHighExeption::GradeTooHighExeption( std::string error ) : std::out_of_range(error)
{
	return ;
}

std::string	Form::getName( void ) const
{
	return (this->name);
}

bool		Form::getSign( void ) const
{
	return (this->isSigned);
}

unsigned int	Form::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

unsigned int	Form::getGradeToExecute( void ) const
{
	return (this->gradeToExecute);
}

void	Form::checkGradeToSign( unsigned int _gradeToSign)
{
	if (_gradeToSign < 1)
		throw Form::GradeTooHighExeption("The grade is too high");
	else if (_gradeToSign > 150)
		throw Form::GradeTooLowExeption("The grade is too low");
	else
		this->gradeToSign = _gradeToSign;
}

void	Form::checkGradeToExecute( unsigned int _gradeToExecute)
{
	if (_gradeToExecute < 1)
		throw Form::GradeTooHighExeption("The grade is too high");
	else if (_gradeToExecute> 150)
		throw Form::GradeTooLowExeption("The grade is too low");
	else
		this->gradeToExecute = _gradeToExecute;
}

void	Form::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowExeption("The grade is too low");
	else
		this->isSigned = true;
}

std::ostream&	operator<<( std::ostream& out, const Form& form )
{
	out << "Form name: " << form.getName() << ", Form sign grade: " \
		<< form.getGradeToSign() << ", Form exec grade: " \
		<< form.getGradeToExecute() << ", Form is signed: " \
		<< (form.getSign() ? "true" : "false");
	return ( out );
}

