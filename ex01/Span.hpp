/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:20:12 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/10 18:21:03 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <cstdlib>
# include <exception>
# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &copy);
		Span const &operator=(Span const &rhs);
		~Span();

		class SpanContainerFull : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanFound : public std::exception
		{
			virtual const char* what() const throw();
		};

		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addRange(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);

	private:
		unsigned int		n_;
		std::vector<int>	numbers_;
};

#endif // SPAN_HPP
