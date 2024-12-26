/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:19:58 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 09:50:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl {

	public:
		void	complain(std::string level);

	private:
		int	getLevel(std::string level);
		
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
};

#endif