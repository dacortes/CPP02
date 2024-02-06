/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:44 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/06 09:23:15 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
/*
 * Constructor && Destructor.
*/
Fixed::Fixed(void)
{
	this->fixedPoint = 0;
}

Fixed::~Fixed(void)
{
}

/*
 * Overloading constructors.
*/
Fixed::Fixed(Fixed &fixp)
{
	*this = fixp;
}

Fixed::Fixed(const Fixed &fixp)
{
	*this = fixp;
}

/*
 * Overloading constructors
*/
Fixed::Fixed(const int num)
{
	this->fixedPoint = (num << this->bits);
}

Fixed::Fixed(const float num)
{
	this->fixedPoint = roundf(num * (1 << this->bits));
}

/*
 * Arithmetic operators.
*/
Fixed	&Fixed::operator=(const Fixed &fixp)
{
	this->fixedPoint = fixp.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixp)
{
	return (this->toFloat() + fixp.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixp)
{
	return (this->toFloat() - fixp.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixp)
{
	return (this->toFloat() * fixp.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixp)
{
	return (this->toFloat() / fixp.toFloat());
}

/*
 *	Comparison operators
*/
bool	Fixed::operator>(const Fixed &fixp) const
{
	return (this->toFloat() > fixp.toFloat());
}

bool	Fixed::operator<(const Fixed &fixp) const
{
	return (this->toFloat() < fixp.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixp) const
{
	return (this->toFloat() >= fixp.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixp) const
{
	return (this->toFloat() <= fixp.toFloat());
}

bool	Fixed::operator==(const Fixed &fixp) const
{
	return (this->toFloat() == fixp.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixp) const
{
	return (this->toFloat() != fixp.toFloat());
}

/*	Define prefix increment operator  */
Fixed	&Fixed::operator++(void)
{
	this->fixedPoint++;
	return (*this);
}

/*	Define postfix increment operator */
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

/*	Define prefix decrement operator  */
Fixed	&Fixed::operator--(void)
{
	this->fixedPoint--;
	return (*this);
}

/*	Define postfix decrement operator */
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--*this;
	return (tmp);
}

/*
 * Methods get.
*/
int	Fixed::getRawBits(void) const
{
	return (this->fixedPoint);
}

/*
 * Methods set.
*/
void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

/*
 * Methods convert.
*/
float	Fixed::toFloat(void) const
{
	return (float(this->fixedPoint) / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->bits);
}

/*
 * Members funtions.
*/
Fixed	&Fixed::min(Fixed &comp1, Fixed &comp2)
{
	return (comp1 < comp2 ? comp1 : comp2);
}

Fixed	&Fixed::max(Fixed &comp1, Fixed &comp2)
{
	return (comp1 > comp2 ? comp1 : comp2);
}

const Fixed	&Fixed::min(const Fixed &comp1, const Fixed &comp2)
{
	return (comp1 < comp2 ? comp1 : comp2);
}

const Fixed	&Fixed::max(const Fixed &comp1, const Fixed &comp2)
{
	return (comp1 > comp2 ? comp1 : comp2);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

