#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ios>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &other);	// recopie
		~Fixed();

		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);

		Fixed& operator=(const Fixed &other);
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);

		static Fixed max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);

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
