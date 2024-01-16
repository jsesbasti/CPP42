/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:28:42 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/10 11:36:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <iomanip>
# include <iostream>
# include <climits>
# include <fstream>
# include <sstream>
# include <stack>
# include <string>

class RPN
{
private:
	RPN( void );
	RPN( const RPN &srcOp );
	~RPN( void );

	RPN	&operator=( const RPN &srcOp );

	static void	parse( std::string operation, std::stack<int> &stack );
	static int	doOp( char op, std::stack<int> &stack );

public:
	static void	rpn( const std::string operation );
	
};

#endif