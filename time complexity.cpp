#include <stdio.h>
#include <stdlib.h>
void matrix_multiply(int **A, int **B, int **C, int num_rows_A, int num_cols_A, int num_rows_B, int num_cols_B) 
{
    if (num_cols_A != num_rows_B)
	 {
        printf("The number of columns in A must be equal to the number of rows in B\n");
        exit(1);
    }
    for (int i = 0; i < num_rows_A; i++) 
	{
        for (int j = 0; j < num_cols_B; j++) 
		{
            C[i][j] = 0;
            for (int k = 0; k < num_cols_A; k++) 
			{
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void calculate_time_complexity(int num_rows_A, int num_cols_A, int num_rows_B, int num_cols_B) 
{
    int num_operations = num_rows_A * num_cols_B * num_cols_A;
    printf("Time complexity: O(%d)\n", num_operations);
}
void print_matrix(int **matrix, int num_rows, int num_cols) 
{
    for (int i = 0; i < num_rows; i++) 
	{
        for (int j = 0; j < num_cols; j++) 
		{
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int num_rows_A = 2;
    int num_cols_A = 2;
    int num_rows_B = 2;
    int num_cols_B = 2;
    int **A = (int **)malloc(num_rows_A * sizeof(int *));
    for (int i = 0; i < num_rows_A; i++) 
	{
        A[i] = (int *)malloc(num_cols_A * sizeof(int));
    }

    int **B = (int **)malloc(num_rows_B * sizeof(int *));
    for (int i = 0; i < num_rows_B; i++) 
	{
        B[i] = (int *)malloc(num_cols_B * sizeof(int));
    }

    int **C = (int **)malloc(num_rows_A * sizeof(int *));
    for (int i = 0; i < num_rows_A; i++) 
	{
        C[i] = (int *)malloc(num_cols_B * sizeof(int));
    }
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    B[0][0] = 5;
    B[0][1] = 6;
    B[1][0] = 7;
    B[1][1] = 8;
    matrix_multiply(A, B, C, num_rows_A, num_cols_A, num_rows_B, num_cols_B);
    printf("Result:\n");
    print_matrix(C, num_rows_A, num_cols_B);
    calculate_time_complexity(num_rows_A, num_cols_A, num_rows_B, num_cols_B);
    for (int i = 0; i < num_rows_A; i++) 
	{
        free(A[i]);
        free(C[i]);
    }
    free(A);
    free(C);

    for (int i = 0; i < num_rows_B; i++) 
	{
        free(B[i]);
    }
    free(B);

    return 0;
}
