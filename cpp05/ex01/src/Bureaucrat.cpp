/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:40:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/12 21:27:07 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Undefined"), grade(MID_GRADE)
{
	std::cout << "You created a bureaucrat." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string _name, unsigned int _grade )
{
	this->name = _name;
	tryGrade(_grade);
	std::cout << "Bureaucrat " << this->getName() << " want the form B3A42 (It does not exist)."<< std::endl;
	return ;
}

Bureaucrat::GradeTooLowExeption::GradeTooLowExeption(std::string error) : std::out_of_range(error)
{
	return ;
}

Bureaucrat::GradeTooHighExeption::GradeTooHighExeption(std::string error) : std::out_of_range(error)
{
	return ;
}

void	Bureaucrat::tryGrade(unsigned int _grade)
{
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighExeption("Grade was too high.");
	else if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowExeption("Grade was too low.");
	else
		this->grade = _grade;
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

	_grade--;
	tryGrade(_grade);
}

void	Bureaucrat::decrementGrade( void )
{
	unsigned int	_grade = this->getGrade();

	_grade++;
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

void	Bureaucrat::signForm( Form &form )
{
	bool	tmp_signed = form.getSign();

	try
	{
		form.beSigned(*this);
		if (tmp_signed == false)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't sign " << form.getName() << " beacause it was signed" << std::endl;
	}
	catch ( std::out_of_range &error)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " beacause " << error.what() << std::endl;
	}
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ( out );
}
