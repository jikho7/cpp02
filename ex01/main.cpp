#include <iostream>
#include "Fixed.hpp"
#include <cmath>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	// bitshifting
	// std::cout << (1 << 0) << std::endl;
	// std::cout << (1 << 1) << std::endl;
	// std::cout << (1 << 2) << std::endl;
	// std::cout << (1 << 3) << std::endl;
	// std::cout << (1 << 4) << std::endl;
	// std::cout << (1 << 5) << std::endl;
	// std::cout << (1 << 6) << std::endl;
	// std::cout << (1 << 7) << std::endl;
	// std::cout << (1 << 8) << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
