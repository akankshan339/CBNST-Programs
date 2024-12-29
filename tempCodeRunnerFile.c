#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return (x+y);         //x0 =0 y0 =1  xn = 1
    //return (y-x)/(y+x);   //x0 =0 y0 =1  xn = 0.1
    //return ((pow(y, 2) - pow(x, 2)) / (pow(y, 2) + pow(x, 2))); //y(0) = 1 i.e x0 = 0 , y0 =1 xn = 0.4 i.e findy(0.4)  = 1.375
}
int main()
{
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;
    int n;
    printf("Enter the inital value of x0 and y0: ");
    scanf("%f%f", &x0, &y0);
    printf("Enter the calculation point: ");
    scanf("%f", &xn);
    printf("Enter no of steps: ");
    scanf("%d", &n);
    h = (xn - x0)/n;
    //apply RK method
    for(int i=0; i<n; i++)
    {
        k1 = h * (f(x0, y0));
        k2 = h * (f((x0+h/2), (y0+k1/2)));
        k3 = h * (f((x0+h/2), (y0+k2/2)));
        k4 = h * (f((x0+h), (y0+k3)));
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        yn = y0 + k;
        //printf("\ny%d for given %f is %f",i+1, x0, yn);
       
        printf("\nCurrent iteration:%d x=%0.3f y=%0.3f", i+1, x0, y0);
        x0 = x0+h;
        y0 = yn;
    }
    printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
    return 0;
}