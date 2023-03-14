/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:09:48 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/13 19:56:34 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

void ScalarConverter::convert(std::string literal)
{
	std::string	c_err = "";
	std::string	i_err = "";
	std::string	f_err = "";
	std::string	d_err = "";
	char		c = 0;
	int			i = 0;
	float		f = 0.0f;
	double		d = 0.0;

	switch (ScalarConverter::getType(literal))
	{
	case CHAR:
		c = static_cast<char>(literal[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break;
	case INT:
		i = stoi(literal);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break;
	case FLOAT:
		f = stof(literal);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		break;
	case DOUBLE:
		d = stod(literal);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		break;
	case T_NAN:
		d = std::nan("");
		f = std::nanf("");
		c_err = "impossible";
		i_err = "impossible";
		break;
	case M_INF:
		d_err = "-inf";
		f_err = "-inf";
		c_err = "impossible";
		i_err = "impossible";
		break;
	case P_INF:
		d_err = "+inf";
		f_err = "+inf";
		c_err = "impossible";
		i_err = "impossible";
		break;
	default:
		break;
	}
	
	if ((c < 32 || c > 127) && c_err == "")
		c_err = "Non displayable";

	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (c_err == "")
		std::cout << c;
	std::cout << c_err << std::endl
			  << "int: ";
	if (i_err == "")
		std::cout << i;
	std::cout << i_err << std::endl
			  << "float: ";
	if (f_err == "")
		std::cout << f;
	std::cout << f_err << "f" << std::endl
			  << "double: ";
	if (d_err == "")
		std::cout << d;
	std::cout << d_err << std::endl;
}

Type	ScalarConverter::getType(std::string literal)
{
	int	dot = 0;

	// Char
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	if (literal == "nan")
		return (T_NAN);
	if (literal == "-inf")
		return (M_INF);
	if (literal == "+inf")
		return (P_INF);
	
	// Float
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			++dot;
		if (literal[i] == 'f' && i == literal.length() - 1)
			return (FLOAT);
		if (!std::isdigit(literal[0]) && !(literal[i] == '.' && dot == 1))
			return (ERROR);
	}
	
	// Int
	if (dot == 0)
		return (INT);
	
	// Double
	return (DOUBLE);
}