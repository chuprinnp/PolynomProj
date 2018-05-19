#pragma once
#include <iostream>
using namespace std;
class Polynom
{

public:
	int power;
	double*coeff;

	Polynom operator+(const Polynom& pol2) {
		int maxpower, minpower;
		Polynom polynom;
		if (power > pol2.power) {

			maxpower = power;
			minpower = pol2.power;
			polynom.power = maxpower;
			polynom.coeff = new double[maxpower];
			for (int i = minpower; i >= 0; i--) {
				polynom.coeff[i] = coeff[i] + pol2.coeff[i];
			}
			for (int i = minpower + 1; i <= maxpower; i++) {
				polynom.coeff[i] = coeff[i];
			}
		}
		else {
			maxpower = pol2.power;
			minpower = power;
			polynom.power = maxpower;
			polynom.coeff = new double[maxpower];
			for (int i = minpower; i >= 0; i--) {
				polynom.coeff[i] = coeff[i] + pol2.coeff[i];
			}
			for (int i = minpower + 1; i <= maxpower; i++) {
				polynom.coeff[i] = pol2.coeff[i];
			}
		}
		for (int i = polynom.power;i >= 0;i--) {
			if (polynom.coeff[i] == 0) {
				polynom.power--;
			}
			else { break; }
		}
		for (int i = polynom.power;i >= 0;i--) {
			if (polynom.coeff[i] == 0) {
				polynom.power--;
			}
			else { break; }
		}
		return polynom;
	}

	Polynom operator-(const Polynom& pol2) {
		int maxpower, minpower;
		Polynom polynom;
		if (power > pol2.power) {
			maxpower = power;
			minpower = pol2.power;
			polynom.power = maxpower;
			polynom.coeff = new double[maxpower];
			for (int i = minpower; i >= 0; i--) {
				polynom.coeff[i] = coeff[i] - pol2.coeff[i];
			}
			for (int i = minpower + 1; i <= maxpower; i++) {
				polynom.coeff[i] = coeff[i];
			}
		}
		else {
			maxpower = pol2.power;
			minpower = power;
			polynom.power = maxpower;
			polynom.coeff = new double[maxpower];
			for (int i = minpower; i >= 0; i--) {
				polynom.coeff[i] = coeff[i] - pol2.coeff[i];
			}
			for (int i = minpower + 1; i <= maxpower; i++) {
				polynom.coeff[i] = -pol2.coeff[i];
			}
		}
		for (int i = polynom.power;i >= 0;i--) {
			if (polynom.coeff[i] == 0) {
				polynom.power--;
			}
			else { break; }
		}
		for (int i = polynom.power;i >= 0;i--) {
			if (polynom.coeff[i] == 0) {
				polynom.power--;
			}
			else { break; }
		}
		return polynom;
	}
	Polynom operator*(const Polynom& pol2) {

		Polynom polynom;
		polynom.power = power + pol2.power;
		polynom.coeff = new double[polynom.power];
		for (int i = 0; i <= polynom.power;i++) {
			polynom.coeff[i] = 0;
		}

		for (int i = power; i >= 0; i--) {
			for (int j = 0; j <= pol2.power;j++) {
				polynom.coeff[i + j] += (coeff[i] * pol2.coeff[j]);
			}
		}
		return polynom;
	}

	Polynom operator+(const double& num) {
		Polynom polynom;
		int mpower = power;
		double* mcoeff = new double[mpower];
		for (int i = mpower; i >= 0; i--) {
			mcoeff[i] = coeff[i];
		}
		mcoeff[0] += num;
		polynom.coeff = mcoeff;
		polynom.power = mpower;


		return polynom;
	}
	Polynom operator-(const double& num) {
		Polynom polynom;
		int mpower = power;
		if (power == 0) mpower = 1;
		double* mcoeff = new double[mpower];
		for (int i = 0; i < mpower; i++) {
			mcoeff[i] = coeff[i];
		}
		mcoeff[0] -= num;
		polynom.coeff = mcoeff;
		polynom.power = mpower;


		return polynom;
	}
	bool operator==(const Polynom& pol) {
		if (power != pol.power) return false;
		for (int i = 0; i <= power; i++) {
			if (coeff[i] != pol.coeff[i])
				return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& s, const Polynom& pol);

};
