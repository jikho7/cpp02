#include "Fixed.hpp"

const int Fixed::_rest = 8;
//(1 << _rest) == / 256

Fixed::Fixed() : _number(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nb)
{
	this->_number = nb * (1 << _rest);
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb)
{
	this->_number = roundf(nb * (1 << _rest));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed& Fixed::operator=(const Fixed &other)// copy assignment operator, utilisé pour copier les données d'un objet existant dans un objet déjà existant.
{
	if (this != &other)
	{
		//std::cout << "Copy assignment operator called" << std::endl;
		this->_number = other.getRawBits(); // copie seulement le champ _number et pas tout l objet.
	}
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

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed res;
	int rawBits;

	rawBits = this->_number + other.getRawBits();
	res.setRawBits(rawBits);
	return res;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed res;
	int rawBits;

	rawBits = this->_number - other.getRawBits();
	res.setRawBits(rawBits);
	return res;
}

Fixed Fixed::operator/(const Fixed &other)
{
	float res_float;

	res_float = (this->toFloat() / other.toFloat());
	Fixed res(res_float);
	return res;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed res;
	int rawBits;

	rawBits = (this->_number * other.getRawBits()) / (1 << this->_rest);
	res.setRawBits(rawBits);
	return res;
}

bool Fixed::operator>(const Fixed &other)
{
	if (this->getRawBits() > other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &other)
{
	if (this->getRawBits() < other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &other)
{
	return (other.getRawBits() == this->getRawBits());
}

bool Fixed::operator>=(const Fixed &other)
{
	if (this->getRawBits() >= other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &other)
{
	if (this->getRawBits() <= other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (other.getRawBits() != this->getRawBits())
		return (1);
	return (0);
}

Fixed& Fixed::operator++() // ++a
{
	this->_number = this->_number + 1;
	return(*this);
}

Fixed Fixed::operator++(int) // a++, functions that differ only in their return type cannot be overloaded
{
	Fixed tmp(*this);
	this->_number = this->_number + 1;
	return(tmp);
}

Fixed& Fixed::operator--() // --a
{
	this->_number = this->_number - 1;
	return(*this);
}

Fixed Fixed::operator--(int) // a--, functions that differ only in their return type cannot be overloaded
{
	Fixed tmp;
	this->_number = this->_number - 1;
	return(tmp);
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
