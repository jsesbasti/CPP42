/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:14:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/03 02:28:17 by jsebasti         ###   ########.fr       */
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
	Contact(void);
	~Contact(void);
	
};

#endif