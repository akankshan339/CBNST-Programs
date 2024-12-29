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
    do
    {
        printf("Enter the number of intervals:");
        scanf("%d", &n);
        if (n % 3 != 0)
        {
            printf("Number of intervals should be multiple of 3.");
        }
    } while (n % 3 != 0);

    printf("Enter the lower limit and upper limit: ");
    scanf("%f%f", &a, &b);
    float h, x, y, notthreesmul = 0.0, threesmul = 0.0;
    h = (float)(b - a) / (float)n;
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        y = f(x);
        if (i % 3 == 0)
            threesmul += 2 * y;
        else
            notthreesmul += 3 * y;
    }
    float res = (3 * h / 8) * (f(a) + f(b) + notthreesmul + threesmul);
    printf("Required value of integral is: %.5f", res);

    return 0;
}