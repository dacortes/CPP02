/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:31:06 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/07 15:45:57 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp" 

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"					//end
# define R "\033[1;31m"    			//red
# define G "\033[1;32m"    			//green
# define Y "\033[1;33m"    			//yellow
# define B "\033[1;34m"    			//blue
# define T "\033[1m\033[1;35m"		//Turquesa
# define C "\033[1;36m"				//Cyan
# define O "\033[1m\033[38;5;208m"	//orange
# define F "\033[38;5;128m"			//purple

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

void	printf_value(std::string msg_true, std::string msg_false,
		const Fixed foo, const Fixed tmp, bool flag)
{
	if (flag == true)
		std::cout << O << msg_true << "\nvalue 1: " << E
			<< foo <<  O <<"\nvalue 2: " << E << tmp << std::endl;
	else
		std::cout << T << msg_false<< "\nvalue 1: " << E
			<< foo << T << "\nvalue 2: " << E<< tmp << std::endl;
	std::cout << O << "val1 mem: " << E << "\033[1m" << &foo << E << std::endl;
	std::cout << O << "val2 mem: " << E << "\033[1m" << &tmp << E << std::endl;
}

void	show_operators(Fixed foo)
{
	Fixed  tmp(foo);

	std::cout << "-----------------------------------\n"
		<< "	TEST COMPARATORS\n" << "-----------------------------------\n";
	std::cout << "\033[1mtest ==" << std::endl;
	printf_value("We have to be equal", "We are not the same", foo, tmp,
			(foo == tmp));
	std::cout << "-----------------------------------\n";
	tmp = 20.0f;
	std::cout << "\033[1mtest !=" << E << std::endl;
	printf_value("We don't have to be the same", "We are equal", foo, tmp,
			(foo != tmp));
	std::cout << "-----------------------------------\n";
	std::cout << "\033[1mtest >" << E << std::endl;
	printf_value("parameter one is greater than parameter two",
			"parameter one is less than parameter two", foo, tmp, (foo > tmp));
	std::cout << "-----------------------------------\n";
	std::cout << "\033[1mtest <" << E << std::endl;
	printf_value("parameter one is greater than parameter two",
			"parameter one is less than parameter two", foo, tmp, (foo < tmp));
	std::cout << "-----------------------------------\n";
	std::cout << "\033[1mtest >=" << E << std::endl;
	printf_value("parameter one is greater than or equal to two",
			"parameter one is less than parameter two", foo, tmp, (foo >= tmp));
	std::cout << "-----------------------------------\n";
	std::cout << "\033[1mtest <=" << E << std::endl;
	printf_value("parameter one is less than or equal",
			"parameter one is greater than or equal to two",
			foo, tmp, (foo <= tmp));
}

void	show_increment_decrement_operator(Fixed &foo)
{
	std::cout << "-----------------------------------\n"
		<< "	TEST INCREMENT && DECREMENT\n" << "-----------------------------------\n";
	std::cout << "-----------------------------------\n";
	std::cout << O << "value: " << E << foo << std::endl;
	std::cout << O << "prefix increment value: " << E << ++foo << std::endl;
	foo = 10;
	std::cout << O << "prostfix increment value: " << E << foo++ << std::endl;
	std::cout << O << "value: " << E << foo << std::endl;
	std::cout << O << "prefix decrement value: " << E << --foo << std::endl;
	std::cout << O << "prefix decrement value: " << E << --foo << std::endl;
	foo = 10;
	std::cout << O << "prostfix decrement value: " << E << foo-- << std::endl;
	std::cout << O << "prostfix decrement value: " << E << foo-- << std::endl;
	std::cout << O << "val: " << E << "\033[1m" << &foo << E << std::endl;
}

int	main(void)
{
	Fixed a(10);
	Fixed b(20);
	
	show_operators(a);
	show_increment_decrement_operator(a);
	a = 15;
	std::cout << O << "value max: " << E << Fixed::max (a, b) << std::endl;
	std::cout << O << "value min: " << E << Fixed::min (a, b) << std::endl;
	return (EXIT_SUCCESS);
}

/*	main eva */
/*int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (EXIT_SUCCESS);
}*/
