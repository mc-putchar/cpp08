/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:59:14 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/10 18:28:11 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <stack>

template<typename T>
MutantStack<T>::MutantStack()	{}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy)	{*this = copy;}

template<typename T>
MutantStack<T> const &MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()	{}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

#endif // MUTANTSTACK_TPP
