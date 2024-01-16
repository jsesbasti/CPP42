/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:36:46 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/10 17:35:00 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {

}

RPN::~RPN( void ) {

}

RPN::RPN( const RPN &srcOp ) {
	(void)srcOp;
}

RPN	&RPN::operator=( const RPN &srcOp ) {
	(void)srcOp;
	return (*this);
}

int		RPN::doOp( char op, std::stack<int> &stack)
{
	int first, second;
	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();

	std::string ops[4] = {"-","+","/","*"};
	int	i;
	for (i = 0; ops[i][0] != op; i++)
		;
	switch (i)
	{
		case 0:
			return (second - first);
		case 1:
			return (second + first);
		case 2:
			if (first == 0)
				throw std::runtime_error("We cannot dived by 0");
			return (second / first);
		case 3:
			double overflow = (static_cast<double>(second) * static_cast<double>(first));
			if (overflow > INT_MAX || overflow < INT_MIN)
				throw std::runtime_error("The result is too high");
			return (second * first);
	}
	return (0);
}

void	RPN::parse( std::string operation, std::stack<int> &stack ) {
	for (size_t i = 0; i < operation.length(); i++)
	{
		if (std::isdigit(operation[i]))
		{
			if ((i > 0 && operation[i - 1] == ' ') || i == 0)
				stack.push(operation[i] - '0');
			else
				throw std::invalid_argument("Please put valid inputs");
		}
		else if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/')
		{
			if (i > 0 && operation[i - 1] == ' ')
			{
				if (stack.size() > 1)
					stack.push(doOp(operation[i], stack));
				else
					throw std::invalid_argument("Please put valid inputs");
			}
			else
				throw std::invalid_argument("Please put valid inputs");
		}
		else if (operation[i] != ' ')
			throw std::invalid_argument("Invalid input every number must be separeted by ' ' (space)");
	}
}

void 	RPN::rpn( const std::string operation ) {
	std::stack<int> stack;

	try
	{
		parse(operation, stack);
		if (stack.size() == 1)
		{
			std::cout << stack.top() << std::endl;
			return ;
		}
		else
			throw std::runtime_error("Something went wrong, check your arguments");
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}