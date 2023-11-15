/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:22:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 11:53:59 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	return ;
}

Intern::~Intern( void )
{
	return ;
}

Intern::Intern( const Intern & srcIntern )
{
	(void)srcIntern;
}

Intern &Intern::operator=( const Intern & srcIntern )
{
	(void)srcIntern;
	return (*this);
}

static AForm	*select_form( int i, std::string _target )
{
	switch (i)
	{
		case 1:
			return (new ShrubberyCreationForm( _target ));
		case 2:
			return (new RobotomyRequestForm( _target ));
		case 3:
			return (new PresidentialPardonForm( _target ));
		default:
			break ;
	}
	return (NULL);
}

AForm	*Intern::makeForm( std::string _name, std::string _target )
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;

	while (i < NUM_FORMS)
	{
		if (!_name.compare(forms[i]))
			return (select_form(i, _target));
		i++;
	}
	std::cerr << "Invalid form " << _name << " don't in my database." << std::endl;
	return (NULL);
}