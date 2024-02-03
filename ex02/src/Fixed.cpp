/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:44 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/03 19:00:02 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
/*
 * Constructor && Destructor.
*/
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Overloading constructors.
*/
Fixed::Fixed(const Fixed &fixp)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = fixp.getRawBits();
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = (num << this->bits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(num * (1 << this->bits));
}

/*
 * Arithmetic operators.
*/
Fixed	&Fixed::operator=(const Fixed &fixp)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
bool	Fixed::operator>(const Fixed &fixp)
{
	return (this->toFloat() > fixp.toFloat());
}

bool	Fixed::operator<(const Fixed &fixp)
{
	return (this->toFloat() < fixp.toFloat());
}


bool	Fixed::operator>=(const Fixed &fixp)
{
	return (this->toFloat() >= fixp.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixp)
{
	return (this->toFloat() <= fixp.toFloat());
}

bool	Fixed::operator==(const Fixed &fixp)
{
	return (this->toFloat() == fixp.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixp)
{
	return (this->toFloat() != fixp.toFloat());
}

/*
 * Methods get.
*/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

/*
 * Methods set.
*/
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}
