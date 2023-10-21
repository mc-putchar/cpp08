/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:35:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/10/21 02:35:22 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

struct NumGen
{
	int		n;
	NumGen (int start) : n(start) {}
	int operator() () {return ++n;}
};

int main()
{
	Span sp = Span(5);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &ex) {
		std::cerr << ex.what() << std::endl;
	}

	sp.addNumber(6);

	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &ex) {
		std::cerr << ex.what() << std::endl;
	}

	sp.addNumber(3);
	sp.addNumber(17);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &ex) {
		std::cerr << ex.what() << std::endl;
	}

	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(42);
	} catch (std::exception &ex) {
		std::cerr << ex.what() << std::endl;
	}

	Span bigSpan = Span(42000);

	for (int i = 0; i < 10; ++i) {
		std::vector<int> tempVector(4200);
		NumGen	numGen(-2100 * (i + 1) * -1);
		std::generate(tempVector.begin(), tempVector.end(), numGen);
		try {
			bigSpan.addRange(tempVector.begin(), tempVector.end());
		} catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << "Longest span is: " << bigSpan.longestSpan() << std::endl;
	std::cout << "Shortest span is: " << bigSpan.shortestSpan() << std::endl;

	return 0;
}
