#include "Fixed.hpp"

const int Fixed::_rest = 8;
//(1 << _rest) == / 256

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nb)
{
	this->_number = nb * (1 << _rest);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb)
{
	this->_number = roundf(nb * (1 << _rest));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const // convertit la valeur en virgule fixe en nombre à virgule flottante
{
	return static_cast<float>(this->_number) / (1 << _rest);
}

int Fixed::toInt( void ) const // convertit la valeur en virgule fixe en nombre entier.
{
	return this->_number / (1 << _rest);
}

std::ostream& operator<<(std::ostream& o, const Fixed &other) // o = out flux
{
    o << other.toFloat();
	return o;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const // retourne la valeur du nombre à virgule fixe sans la convertir.
{
	return (this->_number);
}

void Fixed::setRawBits(int const raw) //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
{
	this->_number = raw;
}
