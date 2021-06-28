#include "iostream"

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	// Set the numerator.
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	// Set the denominator.
	void setDenominator(int denominator)
	{
		this->denominator = denominator;
	}

	// Set the numerator and the denominator.
	void setFraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	// Get the numerator.
	int getNumerator()
	{
		return this->numerator;
	}

	// Get the denominator.
	int getDenominator()
	{
		return this->denominator;
	}

	// Print the fraction.
	void printFraction()
	{
		cout << this->numerator << " / " << this->denominator << endl;
	}
};


class FractionArithmetics
{
private:

	// Given two numbers, find the greatest common divisor.
	int computeGCD(int x, int y)
	{
		int min;  // min: x, y �� �ּҰ�

		if(x > y) min = y;
		else min = x;       // �ּҰ��� ����

		for(int i=min; i>=1; i--)
			if(x%i == 0 && y%i == 0) return i;  // �ִ������� ����
	}

public:
	// Compute the sum of two fractions.
	Fraction computeSumTwoFractions(Fraction f1, Fraction f2)
	{
		Fraction f3;

		f3.setDenominator( f1.getDenominator() * f2.getDenominator() );  // f3�� �и� ����

		int numerator1 = f1.getNumerator() * f2.getDenominator();
		int numerator2 = f1.getDenominator() * f2.getNumerator();
		f3.setNumerator( numerator1 + numerator2 );				  // f3�� ���� ����

		int n = computeGCD( f3.getNumerator() , f3.getDenominator() );  // n: f3�� ���ڿ� �и��� �ִ�����
		f3.setDenominator( f3.getDenominator() / n );
		f3.setNumerator( f3.getNumerator() / n );	  // f3�� ���ڿ� �и� ��н�Ŵ

		return f3;
	}

	// Compute the multiplication of two fractions.
	Fraction computeMultiplyTwoFractions(Fraction f1, Fraction f2)
	{
		Fraction f3;

		f3.setDenominator( f1.getDenominator() * f2.getDenominator() );  // f3�� �и� ����
		f3.setNumerator( f1.getNumerator() * f2.getNumerator() );  // f3�� ���� ����

		int n = computeGCD( f3.getNumerator() , f3.getDenominator() );  // n: f3�� ���ڿ� �и��� �ִ�����
		f3.setDenominator( f3.getDenominator() / n );
		f3.setNumerator( f3.getNumerator() / n );	  // f3�� ���ڿ� �и� ��н�Ŵ

		return f3;
	}
};
