/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:15:37 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/09 18:12:41 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Constructors
		ScavTrap(void);
		ScavTrap(std::string name);

		// Destructor
		~ScavTrap(void);

		// Member functions
		void guardGate(void);
		void attack(const std::string& target);
};

#endif