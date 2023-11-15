/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:22:49 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 11:52:33 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# define NUM_FORMS 3

class Intern
{
public:
	Intern( void );
	~Intern( void );
	Intern( const Intern & srcIntern );

	Intern	&operator=( const Intern & srcIntern );
	
	AForm *makeForm( std::string _name, std::string _target );
};

#endif