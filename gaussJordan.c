#include <stdio.h>
int main(){
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    float A[n][n + 1];
    printf("Enter coefficients for x1, x2, ..., x%d and the constant terms:\n", n);
    for (int i = 0; i < n; i++)    {
        for (int j = 0; j <= n; j++)       {
            scanf("%f", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)    {       
        float diag = A[i][i];		// Make the diagonal element 1
        if (diag == 0)        {
            printf("Unique solution does not exist.\n");
            return -1;
        }
        for (int j = 0; j <= n; j++)      {
            A[i][j] /= diag;
        }
        for (int j = 0; j < n; j++)	{ // Make all other elements in column i zero
            if (j != i)    {
                float factor = A[j][i];
                for (int k = 0; k <= n; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }
    printf("Reduced Row Echelon Form (RREF):\n");
    for (int i = 0; i < n; i++)    {
        for (int j = 0; j <= n; j++)      {
            printf("%.1f\t", A[i][j]);
        }
        printf("\n");
    }

    printf("The solution is : \n");
    for (int i = 0; i < n; i++)    {
        printf("x%d = %.0f\n", i + 1, A[i][n]);
    }
    return 0;
}
