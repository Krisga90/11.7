#pragma once
#include <iostream>
class complex
{
	double A_m;
	double B_m;

public:
	void show()const { std::cout << "A = " << A_m << ", B = " << B_m << std::endl; }
	complex(double A=0, double B=0);
	~complex();
	complex operator+(complex & t)const;
	complex operator-(complex & t)const;
	complex operator*(complex & t)const;
	complex operator*(double a)const;
	friend complex operator*(double a, const complex & t);
	friend complex operator~(const complex & t);
	friend std::ostream & operator<<(std::ostream & os, const complex & t);
	friend bool operator>>(std::istream & os, complex & t);


};

