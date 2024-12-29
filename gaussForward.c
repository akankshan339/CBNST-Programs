#include<stdio.h>
#include<math.h>

int findFact(int num){
    int fact = 1;
    for(int i =1; i<=num; i++)
    {
        fact = fact *i;
    }
    return fact;
}
int main()
{
    int n;
    printf("Enter the no of observation: ");
    scanf("%d",&n);

    float x[n], y[n][n];
    printf("Enter the values of x & y:\n");
    for(int i =0; i<n; i++)
    {
    scanf("%f", &x[i]);
    scanf("%f", &y[i][0]);  //1st column of y
    }

     float xvalue, yvalue, h , u, u1;
    printf("Enter the value of x to find y or f(x):");
    scanf("%f", &xvalue);

    h = x[1] - x[0];
    u = (xvalue - x[0]) / h;

    for(int j=1; j<n; j++)
    {
        for(int i =0; i<n-j; i++)
        {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }
    
    printf("Gauss Forward difference table :\n");
     for(int i =0; i<n; i++)
     {
        printf("%.2f\t", x[i]);
         for(int j =0; j<n-i; j++)
         {
            printf("%.4f\t", y[i][j]);
         }
         printf("\n");
     }
     printf("Gauss Forward Interpolation Formula: \n");
     yvalue = y[0][0];
     u1 = u;
     for(int i=1; i<n; i++){
        yvalue += u1* y[0][i] / findFact(i);
        u1 = u1 *(u-i);
     }
    printf("value of y at x= %.2f is %.4f", xvalue, yvalue);
     return 0;

}