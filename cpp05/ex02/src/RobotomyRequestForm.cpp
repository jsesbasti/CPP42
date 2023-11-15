/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:04:45 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:49:42 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = "Undefined target";
}

RobotomyRequestForm::RobotomyRequestForm( std::string _target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & srcForm ) : AForm(srcForm.getName(), srcForm.getGradeToSign(), srcForm.getGradeToExecute())
{
	this->target = srcForm.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->target);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm & srcForm )
{
	if (this != &srcForm)
	{
		this->target = srcForm.getTarget();
		AForm::operator=(srcForm);
	}
	return (*this);
}

void	RobotomyRequestForm::executeForm( void ) const
{
	static bool	conceed = true;

	if (conceed == true)
	{
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
		conceed = false;
	}
	else
	{
		std::cout << this->getTarget() << " couldn't been robotomized." << std::endl;
		conceed = true;
	}
}