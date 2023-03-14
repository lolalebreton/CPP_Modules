/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:20 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:48 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Character.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		
		// Operators
		Ice & operator=(const Ice &assign);

		// Other member functions
		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif