#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
private:
	int row;
	int column;
	int table[100][100];

public:
	// Initialize the row and the column.
	void initializeMatrix(int row, int column)
	{
		this->row = row;
		this->column = column;
	}

	// Generate a randomized matrix with the row and the column.
	void setRandomMatrix()
	{
		for(int x=0; x < this->row; x++)
			for(int y=0; y < this->column; y++){
				int n = rand() % 30 + 1;
				setMatrixValue(x, y, n);		  //  1~30 ������ ������ ��� ������ ����
			}
	}

	// Set the value for the given row and column position.
	void setMatrixValue(int row_pos, int col_pos, int value)
	{
		this->table[row_pos][col_pos] = value;
	}
	
	// Get the row.
	int getRow()
	{
		return this->row;
	}

	// Get the column.
	int getColumn()
	{
		return this->column;
	}

	// Get the matrix value for the given row and column position.
	int getMatrixValue(int row_pos, int col_pos)
	{
		return this->table[row_pos][col_pos];
	}

	// Print the matrix.
	void printMatrix()
	{
		for(int x=0; x < this->row; x++){
			for(int y=0; y < this->column; y++){
				cout << setw(5) << this->table[x][y];
			}
			cout << endl;
		}
		cout << endl;
	}
};


class MatrixArithmetic
{

public:
	Matrix computeSumTwoMatrices(Matrix a, Matrix b)
	{
		Matrix c;

		c.initializeMatrix( a.getRow() , a.getColumn() );  // ��� c�� ��� ���� ����

		for(int x=0; x < a.getRow(); x++)
			for(int y=0; y < a.getColumn(); y++)
				c.setMatrixValue( x , y , a.getMatrixValue(x, y) + b.getMatrixValue(x, y) );
					// ��� a�� b�� ���� �� ��� c�� ����

		return c;
	}

	Matrix computeMultiplyTwoMatrices(Matrix a, Matrix b)
	{
		Matrix c;
		c.initializeMatrix( a.getRow() , a.getRow() );  // ��� c�� ��� ���� ����

		Matrix b_t;
		b_t.initializeMatrix( a.getColumn() , a.getRow() );  // ��� b_t�� ��� ���� ����

		for(int x=0; x < a.getRow(); x++)
			for(int y=0; y < a.getColumn(); y++)
				b_t.setMatrixValue( y , x , b.getMatrixValue(x, y) );  // ��� b�� ��ġ����� ����

		for(int x=0; x < a.getRow(); x++)
			for(int y=0; y < a.getRow(); y++)
				c.setMatrixValue(x, y, 0);  // ��� c�� ������ ���� �켱 ��� c�� ������ ��� 0���� ����

		for(int x=0; x < a.getRow(); x++)
			for(int y=0; y < a.getRow(); y++)
				for(int i=0; i < a.getColumn(); i++)
					c.setMatrixValue(x, y, c.getMatrixValue(x, y) + a.getMatrixValue(x, i) * b_t.getMatrixValue(i, y) );
						// ��� a�� b_t�� ���� �� ��� c�� ����

		return c;
	}
};