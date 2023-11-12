/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:57:44 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/12 21:28:08 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string		name;
	bool			isSigned;
	unsigned int	gradeToSign;
	unsigned int	gradeToExecute;
	Form( void );

public:
	Form( std::string _name, unsigned int _gradeToSign, unsigned int _gradeToExecute );
	Form( const Form &form );
	~Form( void );
	
	//	Overload

	Form	&operator=( const Form &form );

	//	Execptions

	class GradeTooLowExeption : public std::out_of_range {
		public:
			GradeTooLowExeption( std::string error );
	};

	class GradeTooHighExeption : public std::out_of_range {
		public:
			GradeTooHighExeption( std::string error );
	};

	//	Getters

	std::string		getName( void ) const;
	bool			getSign( void ) const;
	unsigned int	getGradeToSign( void ) const;
	unsigned int	getGradeToExecute( void ) const;

	//	Functions

	void			beSigned( const Bureaucrat &bureaucrat);
	void			checkGradeToSign( unsigned int _gradeToSign );
	void			checkGradeToExecute( unsigned int _gradeToExecute );
};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif