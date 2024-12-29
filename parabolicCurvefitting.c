//for 2nd degree 
#include<stdio.h>

int main()
{
    int n;
    printf("Enter no of data points: ");
    scanf("%d", &n);
    float x[n], y[n], sumX =0, sumY =0, sumX2 =0, sumX3=0, sumX4 =0, sumX2Y = 0, sumXY =0, a, b, c;
    printf("Enter the data points of x: ");
    for(int i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Enter the data points of y: ");
    for(int i=0; i<n; i++)
    {
        scanf("%f",&y[i]);
    }
    for(int i=0; i<n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i]; 
    }
    // y = a+ b*x; // y on x
    // sumY = n*a + sumX *b + c* sumX2;
    // sumXY = sumX *a + sumX2 * b + sumX3 * c;
    // sumX2Y = sumX2 *a + sumX3 *b + sum X4 *c;

    // Calculate coefficients 'a' and 'b' and 'c'
     // Augmented matrix for Gaussian elimination
    float A[3][4] = {
        {n, sumX, sumX2, sumY},       
        {sumX, sumX2, sumX3, sumXY}, 
        {sumX2, sumX3, sumX4, sumX2Y} 
    };

    // Gaussian elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            float ratio = A[j][i] / A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    // Back substitution
    c = A[2][3] / A[2][2];
    b = (A[1][3] - A[1][2] * c) / A[1][1];
    a = (A[0][3] - A[0][2] * c - A[0][1] * b) / A[0][0];

    printf("The equation of the parabolic curve is: y = %.2f + %.2fx + %.2fx^2\n", a, b, c);
return 0;
}