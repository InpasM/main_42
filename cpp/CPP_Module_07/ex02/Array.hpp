/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:14:25 by msapin            #+#    #+#             */
/*   Updated: 2023/11/22 19:03:57 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <sstream>
# include <cstdlib>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

template<typename T>
class Array {

	public:
		Array(void) : _size(0), _array(new T()) {}
		Array(unsigned int n) : _size(n) {

			try
			{
				this->_array = new T[n];
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << RED << BOLD << "Error: " << RESET << e.what() << std::endl;
				exit(-1);
			}
		}
		Array(Array const & copy) {
			this->_size = copy._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = copy._array[i];
		}

		~Array(void) {
			if (!this->_size)
				delete this->_array;
			else
				delete [] this->_array;
		}

		Array & operator=(Array const & src) {
			if (this != &src)
			{
				if (this->_size != 0)
					delete [] this->_array;
				this->_size = src._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
			}
			return *this;
		}

		unsigned int size(void) const {return this->_size;}

		T & operator[](int index) {
			if (index > static_cast<int>(this->_size))
				throw Array::IndexTooHighException();
			else if (index < 0)
				throw Array::IndexTooLowException();
			else
				return this->_array[index];
		}

		T & operator[](unsigned int index) {
			if (index > this->_size)
				throw Array::IndexTooHighException();
			else
				return this->_array[index];
		}

		const T & operator[](int index) const {
			if (index > static_cast<int>(this->_size))
				throw Array::IndexTooHighException();
			else if (index < 0)
				throw Array::IndexTooLowException();
			else
				return this->_array[index];
		}

		const T & operator[](unsigned int index) const {
			if (index > this->_size)
				throw Array::IndexTooHighException();
			else
				return this->_array[index];
		}

		class IndexTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Index: too low!");
				}
		};

		class IndexTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Index: too high!");
				}
		};

	private:
		unsigned int _size;
		T * _array;
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & i) {

	for (unsigned int j = 0; j < i.size(); j++)
		o << "array(" << j << "): " << i._array[j] << std::endl;
	return o;
}

#endif