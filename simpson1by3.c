#include <stdio.h>
#include <math.h>
float f(float x)
{
     return (1/ (1+ (x*x)));
    // return pow(2.718, -0.5) *x ;    //value of e is approximately 2.7182
    //return (sin(x) - log(x) + pow(2.718, x));
}
int main()
{
    int n;
    float a, b;
    printf("Enter the no. of intervals: ");
    do
    {
        scanf("%d", &n);
        if (n % 2 != 0)
            printf("Number of intervals should be even.\n");
    } while (n % 2 != 0);
    printf("Enter the lower limit and upper limit: ");
    scanf("%f%f", &a, &b);
    float h, x, y, sumodd = 0.0, sumeven = 0.0;
    h = (float)(b - a) / (float)n;
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        y = f(x);
        if (i % 2 != 0)
            sumodd += 4 * y; // intermediate terms
        else
            sumeven += 2 * y; // intermediate terms
    }

    float res = (h / 3) * (f(a) + f(b) + sumodd + sumeven);
    printf("Required value of integral is: %.5f", res);

    return 0;
}