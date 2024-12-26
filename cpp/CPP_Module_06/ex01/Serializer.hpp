/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:36 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 13:07:26 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>
# include <string>

# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 

struct Data {
	std::string words;
	int	nbInt;
	float	nbFloat;
	double	nbDouble;
};

class Serializer {
	
	public:
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const & copy);
		~Serializer(void);

		Serializer & operator=(Serializer const & src);
};

#endif