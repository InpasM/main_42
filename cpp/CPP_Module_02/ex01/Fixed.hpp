/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:26:21 by msapin            #+#    #+#             */
/*   Updated: 2023/10/16 10:47:31 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class   Fixed {

	public:
		Fixed(void);
		Fixed(int const numInt);
		Fixed(float const numFloat);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		float   toFloat(void) const;
		int   toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _rawBits;
		static const int _fractBits;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & i);

#endif