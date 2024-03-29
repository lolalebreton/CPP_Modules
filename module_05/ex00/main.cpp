/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lola <lola@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:44 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/14 13:15:29 by lola             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat alice("Alice", 1);
	std::cout << alice << std::endl;
	Bureaucrat bob("Bob", 150);
	std::cout << bob << std::endl;
	try
	{
		alice.deGrade();
		std::cout << alice << std::endl;
		// Bureaucrat charlie("Charlie", 0);
		// std::cout << charlie << std::endl;
		alice.upGrade();
		// alice.upGrade();
		bob.deGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{	
		bob.upGrade();
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}