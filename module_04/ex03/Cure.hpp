/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:20 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/08 14:36:44 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "Character.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		
		// Operators
		Cure & operator=(const Cure &assign);

		// Other member functions
		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif