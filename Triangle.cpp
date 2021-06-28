#include <cmath>

using namespace std;

class Triangle
{
private:
	int s1;
	int s2;
	int s3;
	double area;
	double circumference;

public:
	// Set the width.
	void setThreeSides(int s1, int s2, int s3)
	{
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
	}

	// Check if the three sides can make a valid traiangle.
	bool checkValidTriangle()
	{
		if(this->s1 < this->s2 + this->s3 && this->s2 < this->s1 + this->s3 && this->s3 < this->s1 + this->s2)
			return true;
		else
			return false;
	}

	// Get the area.
	double getArea()
	{
		return this->area;
	}

	// Get the circumference.
	double getCircumference()
	{
		return this->circumference;
	}

	// Calculate the area of the circle.
	void calculateArea()
	{	
		double t = ((double)this->s1 + (double)this->s2 + (double)this->s3) / 2;

		this->area = sqrt( t * (t - (double)this->s1) * (t - (double)this->s2) * (t - (double)this->s3) );
	}

	// Calculate the cumference of the rectangle.
	void calculateCumference()
	{
		this->circumference = this->s1 + this->s2 + this->s3;
	}
};


