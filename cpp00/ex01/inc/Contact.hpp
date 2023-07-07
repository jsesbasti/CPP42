/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:14:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/07 02:16:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>

class Contact
{

private:
	std::string name;
	std::string	surename;
	std::string	nikname;
	std::string	description;
	std::string number;

public:
	//setters
	void	set_name(std::string _name) {
		name = _name;
	}

	void	set_surename(std::string _surename) {
		surename = _surename;
	}

	void	set_des(std::string _des) {
		description = _des;
	}

	void	set_number(std::string _num) {
		number = _num;
	}
	//getters
	std::string	get_surename() {
		return (surename);
	}

	std::string get_name() {
		return (name);
	}

	std::string get_des() {
		return (description);
	}

	std::string get_number() {
		return (number);
	}
	//Constructors
	Contact(void);
	//Destructors
	~Contact(void);
		
};

#endif