/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:50 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:57:20 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(const Ice & copy);
		~Ice(void);

		Ice & operator=(const Ice & src);

		virtual AMateria* clone(void) const;

		virtual void	use(ICharacter & target);

		bool isUsed(void) const;
		void updateUsed(void);

	private:
		bool _used;
};

#endif