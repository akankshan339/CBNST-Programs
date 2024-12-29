#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return (x+y);         //x0 =0 y0 =1  xn = 1
    //return (y-x)/(y+x);   //x0 =0 y0 =1  xn = 0.1
    //return (pow(y, 2) - pow(x, 2)) / (pow(y, 2) - pow(x, 2));
}
int main()
{
    float x0, y0, xn, h, slope, yn;
    int n;
    printf("Enter the inital value of x0 and y0: ");
    scanf("%f%f", &x0, &y0);
    printf("Enter the claculation point: ");
    scanf("%f", &xn);                   //Value of x at which we need approximation
    printf("Enter no of intervals: ");
    scanf("%d", &n);
    h = (xn -x0)/n;
    //apply euler method
    for(int i=0; i<n; i++)
    {
        //slope = f(x0, y0); 
        yn = y0 + h * f(x0, y0);     // or yn = y0 * h * slope;    yn repersent y1, y2, y3... till yn n no of steps
        printf("\nCurrent iteration:%d x=%0.3f y=%0.3f", i+1, x0, y0);
        x0 = x0 +h;
        y0 = yn;
    }
    printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
    return 0;
}