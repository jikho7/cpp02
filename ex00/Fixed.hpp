#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ios>
#include <string>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);	// recopie
		Fixed& operator=(const Fixed &other);	// operateur d assigation

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _number;
		static const int _rest;

};

#endif
