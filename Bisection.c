//Find real root of eq f(x) = x^3 -x -1,  x0  = 1 , x1 = 2 allowederr = 0.0001
//f(x) = x log base 10 x = 1.2 , x log base 10 x - 1.2 = 0
#include<stdio.h>
#include<math.h>

float f(float x)
{
   // return x*x*x -x -1;
   //return (pow(x,3) - x -1);
   return x * log10(x) - 1.2;
}
int main()
{
    float x, x0, x1, allowedErr;
    int flag =0, iter=0;
    
    do
    {
    printf("Enter the value of x0 and x1:\n");
    scanf("%f%f", &x0, &x1);
        if(f(x0) * f(x1) < 0)   {

            flag =1;
            printf("Roots lies between %f and %f \n", x0, x1);
        }
        else    {
            printf("Wrong Interval, Try Again...\n");
        }

    } while (flag != 1);
    printf("Enter Allowed Error: \n");
    scanf("%f", &allowedErr);
    do {
        iter++;
        x = (x0 +x1) /2.0;
        printf("%d iteration , value of x is %f , value of f(%f) is %f\n", iter, x, x, f(x));
    if(fabs(f(x)) <= allowedErr)    {   //|| fabs(x1 - x0) < allowedErr
        flag = 0;
        printf("Root of the equation is %f after %d iteration \n", x, iter);
    }
    else if(f(x0) * f(x) < 0)
         x1 =x;
    else
        x0 = x;
       
    } while (flag != 0);
    
    return 0;
}