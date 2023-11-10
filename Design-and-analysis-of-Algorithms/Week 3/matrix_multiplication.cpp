/* 
   	Week 3 
	Implementation of matrix multiplication
*/
	
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() 
{
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];
    int rowA, colA, rowB, colB;
    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> rowA >> colA;
    cout << "Enter the elements of matrix A: ";
    for(int i = 0; i < rowA; i++) 
        for(int j = 0; j < colA; j++) 
            cin >> matA[i][j];
    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> rowB >> colB;
    cout << "Enter the elements of matrix B: ";
    for(int i = 0; i < rowB; i++) 
        for(int j = 0; j < colB; j++) 
            cin >> matB[i][j];
    if(colA != rowB) 
	{
        cout << "Matrix multiplication is not possible!\n";
        return 0;
    }
    for(int i = 0; i < rowA; i++)
	{
        for(int j = 0; j < colB; j++)
		{
            product[i][j] = 0;
            for(int k = 0; k < colA; k++) 
                product[i][j] += matA[i][k] * matB[k][j];
        }
    }
    cout << "Product of matrix A and B is:\n";
    for(int i = 0; i < rowA; i++) 
	{
        for(int j = 0; j < colB; j++)
            cout << product[i][j] << " ";
        cout << endl;
    }
    return 0;
}