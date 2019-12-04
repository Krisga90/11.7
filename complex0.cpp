#include "complex0.h"
#include <iostream>


complex::complex(double A , double B )
{
	A_m = A;
	B_m = B;
}

complex::~complex()
{

}

complex complex::operator+(complex & t)const
{
	return complex(A_m + t.A_m, B_m + t.B_m);
}

complex complex::operator-(complex & t)const
{
	return complex(A_m - t.A_m, B_m - t.B_m);
}

complex complex::operator*(complex & t)const
{
	return complex (A_m*t.A_m - B_m * t.B_m, A_m*t.A_m + B_m * t.B_m);
}
complex complex::operator*(double m)const
{
	return  complex (A_m*m, B_m*m);
}
complex operator~(const complex & t)
{
	return complex(t.A_m, -t.B_m);
}

std::ostream & operator<<(std::ostream & os, const complex & t)
{
	os << "(" << t.A_m << "," << t.B_m << "i)";
	return os;
}

bool operator>>(std::istream & is,complex & t)
{
	std::cout << "\nPobieranie liczby zespolonej w postaci (A+Bi)\n Podaj A: ";
	if (!(is >> (t.A_m)))
	{
		is.clear();
		while (is.get() != '\n')
			continue;
		std::cout << "Blad pobierania wartosci. Koniec programu.\n";
		return false;
	}

	std::cout << "Podaj B: ";
	if (!(is >> t.B_m))
	{
		is.clear();
		while (is.get() != '\n')
			continue;
		std::cout << "Blad pobierania wartosci. Koniec programu.\n ";
		return false;
	}
	return true;
}

complex operator*(double a, const complex & t)
{
	return t.operator*(a);
}
