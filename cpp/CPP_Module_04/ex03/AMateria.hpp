/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:38 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:56:27 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

class ICharacter;

class AMateria {

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		virtual ~AMateria(void);

		AMateria & operator=(AMateria const & src);

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter & target);

		virtual bool isUsed(void) const = 0;
		virtual void updateUsed(void) = 0;

	protected:
		std::string type;
};

#endif