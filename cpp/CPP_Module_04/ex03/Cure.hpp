/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:54 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:57:07 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(Cure const & copy);
		~Cure(void);

		Cure & operator=(Cure const & src);

		virtual AMateria* clone(void) const;

		virtual void	use(ICharacter & target);

		bool isUsed(void) const;
		void updateUsed(void);

	private:
		bool _used;
};

#endif