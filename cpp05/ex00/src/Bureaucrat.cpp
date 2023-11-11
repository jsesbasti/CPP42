/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:40:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/11 22:47:41 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Undefined"), grade(50)
{
	std::cout << "You created an Undefined bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat( std::string _name, unsigned int _grade )
{
	this->name = _name;
	tryGrade(_grade);
}

Bureaucrat::GradeTooLowExeption::GradeTooLowExeption(std::string error) : std::out_of_range(error)
{
}

Bureaucrat::GradeTooHighExeption::GradeTooHighExeption(std::string error) : std::out_of_range(error)
{
}

void	Bureaucrat::tryGrade(unsigned int _grade)
{
	try
	{
		if (_grade < MAX_GRADE)
			throw false;
		else if (_grade > MIN_GRADE)
			throw true;
		else
			this->grade = _grade;
	}
	catch (bool exeption)
	{
		if (exeption == true)
			Bureaucrat::GradeTooLowExeption("Grade was too low");
		else
			Bureaucrat::GradeTooHighExeption("Grade was too high");
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat &src )
{
	this->name = src.getName();
	this->grade = src.getGrade();
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade( void )
{
	unsigned int	_grade = this->getGrade();

	_grade++;
	tryGrade(_grade);
}

void	Bureaucrat::decrementGrade( void )
{
	unsigned int	_grade = this->getGrade();

	_grade--;
	tryGrade(_grade);
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &src )
{
	if (this != &src)
	{
		this->name = src.getName();
		this->grade = src.getGrade();
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ( out );
}
