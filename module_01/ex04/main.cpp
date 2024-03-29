/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:44:58 by lle-bret          #+#    #+#             */
/*   Updated: 2023/05/17 12:27:57 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ft_replace(std::fstream& file, std::fstream& file_replace, std::string s1, std::string s2)
{
	std::string	content;
	std::string	line;
	size_t	pos;
	size_t	tmp;

	(void) file_replace;
	while (getline(file, line))
	{
		content += line;
		if (file.good())
			content += "\n";
	}
	tmp = 0;
	pos = content.find(s1, 0);
	while (pos != std::string::npos)
	{
		file_replace << content.substr(tmp, pos - tmp);
		file_replace << s2;
		tmp = pos + s1.length();
		pos = content.find(s1, tmp);
	}
	file_replace << content.substr(tmp, content.length() - tmp);
}

int main(int ac, char **av)
{
	std::fstream	file;
	std::fstream	file_replace;
	struct stat		fileInfo;

	if (ac != 4)
	{
		std::cout << "Wrong number of parameters (expected 3)." << std::endl;
		return (0);
	}
	stat(av[1], &fileInfo);
	if (!S_ISREG(fileInfo.st_mode))
	{
		std::cout << "Argument is not path to a regular file." << std::endl;
		return (0);
	}
	file.open(av[1], std::ios::in);
	if (!file)
	{
		std::cout << "File could not be opened." << std::endl;
		return (0);
	}
	if (std::string(av[2]) == "")
		std::cout << "Cannnot replace empty string." << std::endl;
	else
	{
		file_replace.open((std::string(av[1]) + std::string(".replace")).c_str() , std::ios::out);
		if (!file_replace)
			std::cout << "Failed to create new file." << std::endl;
		else
		{
			ft_replace(file, file_replace, std::string(av[2]), std::string(av[3]));
			file_replace.close();
		}
	}
	file.close();
	return (0);
}