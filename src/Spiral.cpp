/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiral_array(int **iarr, int *arr, int k, int m, int n, int row, int column)
{
	if (row >= m && column >= n) return;
	if (m == n && row == m - 1 && column == n - 1) arr[k++] = iarr[row][column];
	int i = row, j = column;
	for (j = column; j <= n - 2; j++)
	{
		arr[k++] = iarr[i][j];
	}
	for (i = row; i <= m - 2; i++)
	{
		arr[k++] = iarr[i][j];
	}
	for (; j>row; j--)
	{
		arr[k++] = iarr[i][j];
	}
	for (; i>column; i--)
	{
		arr[k++] = iarr[i][j];
	}
	spiral_array(iarr, arr, k, m - 1, n - 1, row + 1, column + 1);
	return;
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	int *output_array = (int *)malloc(sizeof(int)*(rows*columns));
	spiral_array(input_array, output_array, 0, rows, columns, 0, 0);
	return output_array;
}

