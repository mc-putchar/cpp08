/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:25:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/10/21 02:25:15 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : n_(n)	{}

Span::Span(Span const &copy)	{*this = copy;}

Span const &Span::operator=(Span const &rhs)
{
	if (this != &rhs) {
		this->numbers_.clear();
		this->numbers_ = rhs.numbers_;
		this->n_ = rhs.n_;
	}
	return *this;
}

Span::~Span()	{}

char const *Span::SpanContainerFull::what() const throw()
{
	return "Container full, cannot add more elements";
}

char const *Span::NoSpanFound::what() const throw()
{
	return "No span found";
}

void Span::addNumber(int number)
{
	if (numbers_.size() < n_) {
		numbers_.push_back(number);
	} else {
		throw SpanContainerFull();
	}
}


void Span::addRange(std::vector<int>::iterator begin,
				std::vector<int>::iterator end)
{
	if (numbers_.size() + std::distance(begin, end) < n_) {
		numbers_.insert(numbers_.end(), begin, end);
	} else {
		throw SpanContainerFull();
	}
}

unsigned int Span::shortestSpan()
{
	if (numbers_.size() < 2)	throw NoSpanFound();
	int res = std::abs(numbers_.at(1) - numbers_.at(0));
	for (std::vector<int>::iterator i = numbers_.begin(); i + 1 != numbers_.end(); ++i) {
		for (std::vector<int>::iterator j = i + 1; j != numbers_.end(); ++j) {
			if (!(res = std::min(std::abs(*j - *i), res)))	return 0;
		}
	}
	return static_cast<unsigned int>(res);
}

unsigned int Span::longestSpan()
{
	if (numbers_.size() < 2)	throw NoSpanFound();
	std::vector<int>::iterator smallest = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::iterator largest = std::max_element(numbers_.begin(), numbers_.end());
	return (static_cast<unsigned int>(*largest - *smallest));
}
