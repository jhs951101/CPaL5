#include "Triangle.cpp"
#include "Fraction.cpp"
#include "Matrix.cpp"
#include <iostream>
#include <ctime>

using namespace std;


void testTriangle()
{
	while (true)
	{
		Triangle triangle;
		
		int s1, s2, s3;

		cout << "Input the first side: ";
		cin >> s1;

		cout << "Input the second side: ";
		cin >> s2;

		cout << "Input the third side: ";
		cin >> s3;

		if (s1 <= 0 || s2 <= 0 || s3 <= 0)
			break;

		triangle.setThreeSides(s1, s2, s3);

		if (triangle.checkValidTriangle() == true)
		{
			triangle.calculateArea();
			triangle.calculateCumference();
			cout << "Area: " << triangle.getArea() << endl;
			cout << "Circumference: " << triangle.getCircumference() << endl << endl;
		}
		else
			cout << "This is no vaild triangle." << endl << endl;
	}
}


void testFraction()
{
	while (true)
	{
		Fraction f1;
		Fraction f2;

		int numerator, denominator;

		cout << "Input the first fraction: ";
		cin >> numerator >> denominator;

		if (numerator <= 0 || denominator <= 0)
			break;

		f1.setFraction(numerator, denominator);

		cout << "Input the second fraction: ";
		cin >> numerator >> denominator;

		if (numerator <= 0 || denominator <= 0)
			break;

		f2.setFraction(numerator, denominator);

		f1.printFraction();
		f2.printFraction();

		FractionArithmetics fa;
		Fraction f3 = fa.computeSumTwoFractions(f1, f2);
		cout << "The sum of two fractions is: ";
		f3.printFraction();

		Fraction f4 = fa.computeMultiplyTwoFractions(f1, f2);
		cout << "The multiplication of two factions is: ";
		f4.printFraction();
		cout << endl;
	}
}


void testMatrix()
{
	while (true)
	{
		int row, column;

		cout << "Input the row and column: ";
		cin >> row >> column;

		if (row <= 0 || column <= 0)
			break;

		srand(unsigned int(time(NULL)));

		Matrix m1;
		m1.initializeMatrix(row, column);
		m1.setRandomMatrix();
		m1.printMatrix();

		Matrix m2;
		m2.initializeMatrix(row, column);
		m2.setRandomMatrix();
		m2.printMatrix();

		MatrixArithmetic ma;

		Matrix m3 = ma.computeSumTwoMatrices(m1, m2);
		cout << "The sum of two matrics is: " << endl;
		m3.printMatrix();

		Matrix m4 = ma.computeMultiplyTwoMatrices(m1, m2);
		cout << "The multiplication of two matrics is: " << endl;
		m4.printMatrix();
	}
}

int main()
{
	testTriangle();
	testFraction();
	testMatrix();

	return 0;
}