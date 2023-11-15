/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:50:09 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:38:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string		target;
	void			executeForm( void ) const;
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string _target );
	~PresidentialPardonForm( void );
	PresidentialPardonForm( const PresidentialPardonForm & srcForm );

	PresidentialPardonForm	&operator=( const PresidentialPardonForm & srcForm );
	std::string				getTarget( void ) const;
};

#endif