//10x1 -7x2 +3x3 = 5
//-6x1 +8x2 +4x3 = 7
//2x1 +6x2 =9x3 = -1

#include<stdio.h>
int main()
{
    int n;
    printf("Enter order of matrix :\n");
    scanf("%d", &n);

    float mat[n][n+1];
   printf("Enter coefficients for x1, x2, ..., x%d and the constant terms:\n", n);
   // printf("Enter augmented matrix elements row-wise:\n");
    for(int i =0; i<n; i++)             //row
    {
        for(int j =0; j<n+1; j++)       //column 
        {
            scanf("%f", &mat[i][j]);
        }
    }

    //convert matrix into upper triangular matrix
      for(int i =0; i<n; i++)             //row
    {
        for(int j =i+1; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                printf("Unique solution does not exist: \n");
                return -1;
            }

          //  float c =  mat[j][i] / mat[i][i];
            for(int k =0 ; k<n+1; k++)
            {
                mat[j][k] = mat[j][k] - (mat[j][i] / mat[i][i]) * mat[i][k];
            }
        }
    }

    printf("Upper Triangular Matrix :\n");
    for(int i =0; i<n; i++)             //row
    {
        for(int j =0; j<n+1; j++)       //column 
        {
            printf("%.0f\t", mat[i][j]);
        }
        printf("\n");
    }


    //Applying Backward substitution  For Gauss Elimination
    float x[n];  // Array to store solutions

    // Start from the last equation and work upwards
    // x[n-1] = (float) mat[n-1][n] /mat[n-1][n-1];           //for 0 based indexing
   // for(int i = n-2; i >= 0; i--)  
    for(int i = n-1; i >= 0; i--)     
    {
       //int sum =0;                       // Start with the constant term (right-hand side)
        x[i] = mat[i][n];  
        for(int j = i+1; j < n; j++)                    // Subtract known values from the sum
        {
           // sum = sum + mat[i][j] * x[j];
            x[i] = x[i] - mat[i][j] * x[j];
        }
        // x[i] = (float)(mat[i][n]-sum) /mat[i][i];
        x[i] = x[i] / mat[i][i];                    // Divide by the coefficient of the current variable
    }

    // Print the solutions
    printf("The solutions are:\n");
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %.3f\n", i + 1, x[i]);  // Print each solution
    }
    return 0;
}


//2nd method 

// #include<stdio.h>
// int main()
// {
//     int i,j,k,n;
//     float A[20][20],c,x[10],sum=0.0;
//     printf("\nEnter the order of matrix: ");
//     scanf("%d",&n);
//     printf("\nEnter the elements of augmented matrix row-wise:\n\n");
//     for(i=1; i<=n; i++)
//     {
//         for(j=1; j<=(n+1); j++)
//         {
//             printf("A[%d][%d] : ", i,j);
//             scanf("%f",&A[i][j]);
//         }
//     }
//     for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
//     {
//         for(i=1; i<=n; i++)
//         {
//             if(i>j)
//             {
//                 c=A[i][j]/A[j][j];
//                 for(k=1; k<=n+1; k++)
//                 {
//                     A[i][k]=A[i][k]-c*A[j][k];
//                 }
//             }
//         }
//     }
//     x[n]=A[n][n+1]/A[n][n];
//     /* this loop is for backward substitution*/
//     for(i=n-1; i>=1; i--)
//     {
//         sum=0;
//         for(j=i+1; j<=n; j++)
//         {
//             sum=sum+A[i][j]*x[j];
//         }
//         x[i]=(A[i][n+1]-sum)/A[i][i];
//     }
//     printf("\nThe solution is: \n");
//     for(i=1; i<=n; i++)
//     {
//         printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
//     }
//     return(0);
// }