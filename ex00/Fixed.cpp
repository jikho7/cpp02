#include "Fixed.hpp"

const int Fixed::_rest = 8;

Fixed::Fixed() : _number(0)
{
	//this->_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) //copy constructor, utilisé pour créer un nouvel objet à partir d'un objet existant.
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // copie tout l onjet other dans this
	return;
}


// assignement copy est appelé lorsque vous utilisez l'opérateur d'assignation (=) pour copier les données de l'objet other dans l'objet courant (*this).
Fixed& Fixed::operator=(const Fixed &other)// copy assignment operator, utilisé pour copier les données d'un objet existant dans un objet déjà existant.
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_number = other.getRawBits(); // copie seulement le champ _number et pas tout l objet.
	}
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
