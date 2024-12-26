/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:35 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 17:28:36 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const & copy) {
	*this = copy;
}

Serializer::~Serializer(void) {}

Serializer & Serializer::operator=(Serializer const & src) {

	if (this != &src)
		*this = src;
	return *this;
}

uintptr_t Serializer::serialize(Data * ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
