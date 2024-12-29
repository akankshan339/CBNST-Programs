#include<stdio.h>

int main()
{
    int n;
    printf("Enter no of data points: ");
    scanf("%d", &n);
    float x[n], y[n], sumX =0, sumY =0, sumXY =0, sumX2 =0, a, b;
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
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    // y = a+ b*x; // y on x
    // sumY = n*a + sumX *b;
    // sumXY = sumX *a + sumX2 * b;

    // Calculate coefficients 'a' and 'b'
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    printf("The linear equation is: y = %.2f + %.2f * x\n", a, b);
return 0;
}