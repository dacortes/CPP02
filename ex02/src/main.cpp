/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:31:06 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/05 18:37:20 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp" 

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(2.05f) * Fixed(3));

	std::cout << "result: a:"<<  a << std::endl;
	std::cout << "result: a:"<<  b << std::endl;
	return (EXIT_SUCCESS);
}
