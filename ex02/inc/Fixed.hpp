/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:40:43 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/05 14:58:32 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed
{
	private:
		int	fixedPoint;
		static const int bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed &fixp);
		Fixed(const Fixed &fixp);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &fixp);
		/*
		 *Arithmetic operators  
		*/
		Fixed operator+(const Fixed &fixp);
		Fixed operator-(const Fixed &fixp);
		Fixed operator*(const Fixed &fixp);
		Fixed operator/(const Fixed &fixp);
		/*
		 * Comparison operators
		*/
		bool	operator>(const Fixed &fixp) const;
		bool	operator<(const Fixed &fixp) const;
		bool	operator>=(const Fixed &fixp) const;
		bool	operator<=(const Fixed &fixp) const;
		bool	operator==(const Fixed &fixp) const;
		bool	operator!=(const Fixed &fixp) const;
		/*
		 * Members funtions
		*/
		static 	Fixed	&min(Fixed &comp1, Fixed &comp2);
		static	Fixed	&max(Fixed &comp1, Fixed &comp2);
		static	const Fixed	&min(const Fixed &comp1, const Fixed &comp2);
		static	const Fixed	&max(const Fixed &comp1, const Fixed &comp2);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
