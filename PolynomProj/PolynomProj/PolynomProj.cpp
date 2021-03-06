// PolynomProj.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Polynom.h"
using namespace std;

Polynom newPolynom() {
	Polynom polynom;

	cout << "enter power, then coefficients ";
	cin >> polynom.power;
	polynom.coeff = new double[polynom.power];
	for (int i = polynom.power;i >= 0;i--) {
		cin >> polynom.coeff[i];
	}
	for (int i = polynom.power;i >= 0;i--) {
		if (polynom.coeff[i] == 0) {
			polynom.power--;
		}
		else { break; }
	}
	return polynom;
}

ostream& operator <<(ostream& out, const Polynom& pol) {
	for (int i = pol.power; i > 0; i--) {
		out << pol.coeff[i] << "*x^" << i << " + ";
	}
	out << pol.coeff[0];
	return out;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Polynom a = newPolynom();
	Polynom b = newPolynom();
	cout << "sum result" << endl;
	cout << a + b << endl;
	cout << "subtract result" << endl;
	cout << a - b << endl;
	cout << "multiply result" << endl;
	cout << a * b << endl;
	cout << a + 5 << endl;
	if (a == b) cout << "polynoms are equal" << endl;
	return 0;
}