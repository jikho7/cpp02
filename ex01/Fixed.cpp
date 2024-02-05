#include "Fixed.hpp"

const int Fixed::_rest = 8;

Fixed::Fixed() // _number(0)
{
	this->_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) //Fixed(const Fixed& const); COPIE
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed& Fixed::operator=(const Fixed &other)//Fixed& operator=(const Fixed& other);
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const // retourne la valeur du nombre à virgule fixe sans la convertir.
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw) //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
{
	this->_number = raw;
}
