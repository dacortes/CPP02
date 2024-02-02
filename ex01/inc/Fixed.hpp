/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:40:43 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/02 18:24:34 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Fixed
{
	private:
		int	fixedPoint;
		static const int bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &fixp);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &fixp);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif
