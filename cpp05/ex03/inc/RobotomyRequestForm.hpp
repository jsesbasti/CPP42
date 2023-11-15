/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:10 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:49:50 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	void			executeForm( void ) const;
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string _target );
	RobotomyRequestForm( const RobotomyRequestForm & srcForm );
	~RobotomyRequestForm( void );
	
	RobotomyRequestForm	&operator=( const RobotomyRequestForm & srcForm );
	std::string			getTarget( void ) const;
};

#endif