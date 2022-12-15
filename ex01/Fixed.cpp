/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:29 by snair             #+#    #+#             */
/*   Updated: 2022/12/15 16:16:32 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructore for Fixed class 
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

//default destructor for Fixed class 
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//copy constructor for Fixed class
/*used to  initialize the data members of the class using another object of the same class
copies the values of the data variables of one object of a class to the data member 
of another object of the same class*/
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//contructor for const int variable for Fixed class
/*converts it to the corresponding fixed-point value by
left bitshifting by _bits amount or by multipling 2^_bits*/
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_bits;
}

//contructor for const float variable for Fixed class
/*converts it to the corresponding fixed-point value by
the float value mulitplied by 1<<_bits amount and then rounding it of*/
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1<< this->_bits));
}

//copy assignment operator for Fixed class
/*used to copy values from one object to another already existing object
replaces the contents of existing objects*/
Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

//gets the value of _value class member
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

//sets the value of _value class member
void	Fixed::setRawBits(const int value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = value;
}

/*coverts fixed-point value to corresponding floating-point value
by dividing it by 1 << _bits/ 2^_bits*/
float	Fixed::toFloat(void) const
{
	return ((float)this->_value/(float)(1 << this->_bits));
}

/*coverts fixed-point value to corresponding integer value
multiplying it by 2^-_bits or _value >> _bits*/
int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

//inserts _value in float from Fixed class into output stream
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	 out << fixed.toFloat();
	 return (out);
}