/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:34:11 by msapin            #+#    #+#             */
/*   Updated: 2023/11/08 13:23:05 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

# ifndef NB_IDEA
#  define NB_IDEA 100
# endif

class Brain {

	public:
		Brain(void);
		Brain(Brain const & copy);
		~Brain(void);

		Brain & operator=(Brain const & src);

		void    addIdea(std::string idea, int index);

		std::string	getIdea(int index) const;

	private:
		std::string	_ideas[NB_IDEA];
};

std::ostream &	operator<<(std::ostream & o, Brain const & i);

#endif