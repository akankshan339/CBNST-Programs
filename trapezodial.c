//
#include <stdio.h>
#include <math.h>
float f(float x)
{
    // return 1/ (1+ (x*x));
    // return pow(2.718, -0.5) *x ;    //value of e is approximately 2.7182
    return (sin(x) - log(x) + pow(2.718, x));
}
int main()
{
    int n;
    float a, b;
    printf("Enter the no. of intervals: ");
    scanf("%d", &n);
    printf("Enter lower limit and upper limit: ");
    scanf("%f%f", &a, &b);
    float h, x, y, sum = 0;
    h = (float)(b - a) / n; // b upper limit - lower limit(a)
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        y = f(x);
        sum = sum + (2 * y); // intermediate terms
    }
    float res = (h / 2) * (f(a) + f(b) + sum);
    printf("Required value of integral is: %.5f", res);
    return 0;
}