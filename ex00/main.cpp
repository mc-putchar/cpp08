/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:57:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/10/21 01:57:00 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> range(5);

	range.push_back(1);
	range.push_back(21);
	range.push_back(-21);
	range.push_back(10);
	range.push_back(42);

	std::vector<int>::iterator it = easyfind(range, 742);
	if (it == range.end()) {
		std::cout << "Value not found in range" << std::endl;
	} else {
	 	std::cout << "Found value: " << *it << std::endl;
	}

	it = easyfind(range, 42);
	if (it == range.end()) {
		std::cout << "Value not found in range" << std::endl;
	} else {
	 	std::cout << "Found value: " << *it << std::endl;
	}

	return 0;
}
