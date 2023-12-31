/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:52:42 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/14 10:44:52 by jsebasti         ###   ########.fr       */
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
	this->gradeToSign = _gradeToSign;
	this->gradeToExecute = _gradeToExecute;
	this->checkGradeToSign();
	this->checkGradeToExecute();
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

Form	&Form::operator=( const Form &form )
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

void	Form::checkGradeToSign( void ) const
{
	if (this->gradeToSign < 1)
		throw Form::GradeTooHighExeption("The grade is too high");
	else if (this->gradeToSign > 150)
		throw Form::GradeTooLowExeption("The grade is too low");
}

void	Form::checkGradeToExecute( void ) const
{
	if (this->gradeToExecute < 1)
		throw Form::GradeTooHighExeption("The grade is too high");
	else if (this->gradeToExecute> 150)
		throw Form::GradeTooLowExeption("The grade is too low");
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
