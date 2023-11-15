/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:57:44 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:37:35 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string		name;
	bool			isSigned;
	unsigned int	gradeToSign;
	unsigned int	gradeToExecute;
	AForm( void );
	void			checkGradeToSign( void ) const;
	void			checkGradeToExecute( void ) const;
	virtual void	executeForm( void ) const = 0;

public:
	AForm( std::string _name, unsigned int _gradeToSign, unsigned int _gradeToExecute );
	AForm( const AForm &form );
	virtual ~AForm( void );
	
	//	Overload

	AForm	&operator=( const AForm &form );

	//	Execptions

	class GradeTooLowExeption : public std::out_of_range {
		public:
			GradeTooLowExeption( std::string error );
	};

	class GradeTooHighExeption : public std::out_of_range {
		public:
			GradeTooHighExeption( std::string error );
	};

	class NotSignedExeption : public std::logic_error {
		public:
			NotSignedExeption( std::string error );
	};

	//	Getters

	std::string			getName( void ) const;
	bool				getSign( void ) const;
	unsigned int		getGradeToSign( void ) const;
	unsigned int		getGradeToExecute( void ) const;

	//	Functions
	virtual	std::string	getTarget( void ) const = 0;
	void				beSigned( const Bureaucrat &bureaucrat);
	void				execute( const Bureaucrat & executor) const;

};

std::ostream&	operator<<( std::ostream& out, const AForm& form );

#endif