/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:45:25 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/10 18:27:13 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack const &operator=(MutantStack const &rhs);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator muterator;

		muterator begin(void);
		muterator end(void);
};

# include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
