/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:31:06 by dacortes          #+#    #+#             */
/*   Updated: 2024/02/03 19:00:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp" 

int	main(void)
{
	Fixed a(2);
	Fixed b(2);

	std::cout << (a == b) << std::endl;
	return (EXIT_SUCCESS);
}
