/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:37 by snair             #+#    #+#             */
/*   Updated: 2022/12/01 07:38:51 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(const int value);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

		//4 arithmetic operators: +, -, *, and /
		float 	operator+(Fixed num) const;
		float	operator-(Fixed num) const;
		float	operator*(Fixed num) const;
		float	operator/(Fixed num) const;

		//6 comparison operators: >, <, >=, <=, == and !=
		bool	operator>(Fixed fixed) const;
		bool	operator<(Fixed fixed) const;
		bool	operator>=(Fixed fixed) const;
		bool	operator<=(Fixed fixed) const;
		bool	operator==(Fixed fixed) const;
		bool	operator!=(Fixed fixed) const;

		//4 increment/decrement ++i,i++,--i,i--;
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static Fixed		&min(Fixed &x, Fixed &y);
		static const Fixed	&min(Fixed const &x, Fixed const &y);
		static Fixed		&max(Fixed &x, Fixed &y);
		static const Fixed	&max(Fixed const &x, Fixed const &y);

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif