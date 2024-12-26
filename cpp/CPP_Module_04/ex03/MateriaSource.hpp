/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:07 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:58:13 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & src);

		void learnMateria(AMateria* rhs);
		AMateria* createMateria(std::string const & type);

		void displayContent(void) const;

	protected:
		AMateria* _materiaArray[4];
};

#endif