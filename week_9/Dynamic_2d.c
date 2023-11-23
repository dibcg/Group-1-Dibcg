#include <stdio.h>

void access_2D (int** Matrix, int col, int row)
{
    // Change the way you like

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
            Matrix[j][i] = i*j;
        printf("\n");
    }
}

void print_2D (int** Matrix, int col, int row)
{
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            printf ("%d ", Matrix[j][i]);
}

void free_Matrix (int** Matrix, int col)
{
    for (int i=0; i<col; i++)
        free(Matrix[i]);

    free (Matrix);
}

int main()
{
    int m,n;

    printf("Input the number of columns: = "); 

    scanf("%d",m);

    printf("Input the number of rows: = "); 

    scanf("%d",n);

    // Create the 2-dimensional array
    int** Matrix = (int **) malloc(sizeof(int*) * m);

    for (int i = 0; i<m; i++)
        Matrix[i] = (int *) malloc (sizeof(int) * n);

    // Access the created 2-dimensional array

    access_2D(Matrix,m,n);

    // Print the 2-dimensional array

    print_2D(Matrix,m,n); 

    // Free Matrix

    free_Matrix(Matrix, m);

    return (0);
}