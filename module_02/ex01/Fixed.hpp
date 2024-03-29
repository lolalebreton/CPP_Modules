/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:56:44 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/09 18:16:12 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>



class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int n);
		Fixed(const float f);

		// Destructor
		~Fixed();

		// Operators
		Fixed & operator=(const Fixed &assign);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& f);

		// Getters / Setters
		int getRawBits() const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
		
	private:
		int _RawBits;
		const int _FracBits;
};

#endif