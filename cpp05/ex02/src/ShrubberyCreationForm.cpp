/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:10:15 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/15 10:58:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "Undefined target";
	this->file = this->getTarget() + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string _target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = _target;
	this->file = this->getTarget() + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & srcForm ) : AForm(srcForm.getName(), srcForm.getGradeToSign(), srcForm.getGradeToExecute())
{
	this->target = srcForm.getTarget();
	this->file = srcForm.getTarget() + "_shrubbery";
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm & srcForm )
{
	if (this != &srcForm)
	{
		this->target = srcForm.getTarget();
		this->file = srcForm.getTarget() + "_shrubbery";
		AForm::operator=(srcForm);
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->target);
}

void	ShrubberyCreationForm::executeForm( void ) const
{
	std::ofstream	ofs(this->file);
	if (!ofs.is_open())
	{
		std::cerr << "Error opening " << this->file << std::endl;
		return ;
	}
	ofs << "                                                         . \n";
	ofs << "                                              .         ;  \n";
	ofs << "                 .              .              ;%     ;;   \n";
	ofs << "                   ,           ,                :;%  %;    \n";
	ofs << "                    :         ;                   :;%;'     ., \n";
	ofs << "           ,.        %;     %;            ;        %;'    ,; \n";
	ofs << "             ;       ;%;  %%;        ,     %;    ;%;    ,%' \n";
	ofs << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'  \n";
	ofs << "               ;%;      %;        ;%;        % ;%;  ,%;' \n";
	ofs << "                `%;.     ;%;     %;'         `;%%;.%;' \n";
	ofs << "                 `:;%.    ;%%. %@;        %; ;@%;%' \n";
	ofs << "                    `:%;.  :;bd%;          %;@%;' \n";
	ofs << "                      `@%:.  :;%.         ;@@%;'    \n";
	ofs << "                        `@%.  `;@%.      ;@@%;       \n";
	ofs << "                          `@%%. `@%%    ;@@%;        \n";
	ofs << "                            ;@%. :@%%  %@@%;       \n";
	ofs << "                              %@bd%%%bd%%:;     \n";
	ofs << "                               #@%%%%%:;;      \n";
	ofs << "                                %@@%%%::;      \n";
	ofs << "                                %@@@%(o);  . ' \n";
	ofs << "                                %@@@o%;:(.,'    \n";
	ofs << "                            `.. %@@@o%::;        \n";
	ofs << "                               `)@@@o%::;         \n";
	ofs << "                                %@@(o)::;        \n";
	ofs << "                               .%@@@@%::;         \n";
	ofs << "                               ;%@@@@%::;.         \n";
	ofs << "                             ;%@@@@%%:;;;. \n";
	ofs << "                          ...;%@@@@@%%:;;;;,.. \n";
	return ;
}
