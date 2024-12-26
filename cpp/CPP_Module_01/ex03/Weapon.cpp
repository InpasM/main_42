/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:46:13 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 22:20:19 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {

}

std::string const &	Weapon::getType(void) const {
	return this->_type;
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}
