/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:42:36 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/11 22:45:39 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include <stdexcept>

# define MAX_GRADE 1
# define MIN_GRADE 150
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

class Bureaucrat {

private:

	std::string			name;
	unsigned int		grade;
	void				tryGrade(unsigned int _grade);

public:
	Bureaucrat( void );
	Bureaucrat( std::string _name, unsigned int _grade );
	Bureaucrat( const Bureaucrat &src );
	~Bureaucrat( void );
	
	Bureaucrat	&operator=( const Bureaucrat &src );

	std::string		getName( void ) const;
	unsigned int	getGrade( void ) const;

	void			incrementGrade( void );
	void			decrementGrade( void );
	class			GradeTooHighExeption : public std::out_of_range {
		public:
			GradeTooHighExeption( std::string error );
	};
	class			GradeTooLowExeption : public std::out_of_range {
		public:
			GradeTooLowExeption( std::string error );
	};
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif