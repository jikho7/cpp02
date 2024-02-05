#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ios>
#include <string>

class Fixed
{
	public:
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();
		Fixed(const Fixed &other);	// recopie
		Fixed& operator=(const Fixed &other);	// operateur d assigation

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const; // convertit la valeur en virgule fixe en nombre à virgule flottante
		int toInt( void ) const; // convertit la valeur en virgule fixe en nombre entier.

	private:
		int _number;
		static const int _rest;

};
	std::ostream& operator<<(std::ostream& o, const Fixed &other);
#endif
