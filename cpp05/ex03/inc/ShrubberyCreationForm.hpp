/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:40 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:38:25 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string 	target;
	std::string		file;
	void			executeForm( void ) const;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string _target );
	ShrubberyCreationForm( const ShrubberyCreationForm & srcForm );
	~ShrubberyCreationForm( void );
	
	ShrubberyCreationForm	&operator=( const ShrubberyCreationForm & srcForm );
	std::string				getTarget( void ) const;
};

#endif