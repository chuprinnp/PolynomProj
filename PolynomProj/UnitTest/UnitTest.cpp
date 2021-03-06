#include "gtest\gtest.h"
#include "Polynom.h"

TEST(Polynom, equality) {
	double coeffs[] = { -4 , 5.6, -78, 56 };
	double coeffs2[] = { 456, 55 };
	Polynom pol1;
	Polynom pol2;
	Polynom pol3;
	pol1.power = 3;
	pol2.power = 3;
	pol3.power = 1;
	pol1.coeff = coeffs;
	pol2.coeff = coeffs;
	pol3.coeff = coeffs2;
	EXPECT_TRUE(pol1 == pol2);
}

TEST(Polynom, summp) {
	double coeffs[] = { -4 , 5.6, -78, 56 };
	double coeffs2[] = { 456, 55 };
	double coeffs3[] = { 452 ,60.6, -78, 56 };
	Polynom pol1;
	Polynom pol2;
	Polynom pol3;
	pol1.power = 3;
	pol2.power = 1;
	pol3.power = 3;
	pol1.coeff = coeffs;
	pol2.coeff = coeffs2;
	pol3.coeff = coeffs3;
	EXPECT_TRUE((pol1 + pol2) == pol3);
}

TEST(Polynom, summn) {
	double coeffs[] = { -4 , 5.6, -78 };
	double coeffs2[] = { 4 , 5.6, -78 };
	Polynom pol1;
	Polynom pol2;
	pol1.power = 2;
	pol2.power = 2;
	pol1.coeff = coeffs;
	pol2.coeff = coeffs2;
	EXPECT_TRUE((pol1 + 8) == pol2);
}

TEST(Polynom, subtract) {
	double coeffs[] = { -4 , 5.6, -78, 56 };
	double coeffs2[] = { 456, 55 };
	double coeffs3[] = { 452 ,60.6, -78, 56 };
	Polynom pol1;
	Polynom pol2;
	Polynom pol3;
	pol1.power = 3;
	pol2.power = 1;
	pol3.power = 3;
	pol1.coeff = coeffs;
	pol2.coeff = coeffs2;
	pol3.coeff = coeffs3;
	EXPECT_TRUE((pol3 - pol1) == pol2);
}

TEST(polynom, multiply) {
	double coeffs[] = { 1 , 2 , 3 };
	double coeffs2[] = { 2 , 4 , 1 };
	double coeffs3[] = { 2 , 8 , 15 , 14 , 3 };
	Polynom pol1;
	Polynom pol2;
	Polynom pol3;
	pol1.power = 2;
	pol2.power = 2;
	pol3.power = 4;
	pol1.coeff = coeffs;
	pol2.coeff = coeffs2;
	pol3.coeff = coeffs3;
	EXPECT_TRUE((pol1 * pol2) == pol3);
}

