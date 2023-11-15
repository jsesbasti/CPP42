/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:02:48 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:50:17 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "Undefined target";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string _target ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = _target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & srcForm ) : AForm(srcForm.getName(), srcForm.getGradeToSign(), srcForm.getGradeToExecute())
{
	this->target = srcForm.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm & srcForm )
{
	if (this != &srcForm)
	{
		this->target = srcForm.getTarget();
		AForm::operator=(srcForm);
	}
	return (*this);
}

void	PresidentialPardonForm::executeForm( void ) const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->target);
}