/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:29 by snair             #+#    #+#             */
/*   Updated: 2022/11/30 16:56:31 by snair            ###   ########.fr       */
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

//sets the value of _value class member
void	Fixed::setRawBits(const int value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = value;
}