//Find Best Approximation of 1/3 true val = 0.33333333
//(i)0.30     (ii)0.33    (iii)0.34
#include<stdio.h>
#include<math.h>

float absoluteError(float true_val, float approx_val)
{
float Ea = fabs(true_val - approx_val);
return Ea;
}

int main()
{
    float true_val, approx_val1, approx_val2, approx_val3, Ea1, Ea2, Ea3;
    printf("Enter the true value : \n");
    scanf("%f",&true_val);
    
    printf("Enter the approximate value 1 : \n");
    scanf("%f",&approx_val1);
    printf("Enter the approximate value 2 : \n");
    scanf("%f",&approx_val2);
    printf("Enter the approximate value 3 : \n");
    scanf("%f",&approx_val3);
    Ea1=absoluteError(true_val, approx_val1);
    Ea2=absoluteError(true_val, approx_val2);
    Ea3=absoluteError(true_val, approx_val3);
    if(Ea1 < Ea2 && Ea1 < Ea3)
    {
        printf("Best Approximation is :%2f\n",approx_val1);
    }
    else if(Ea2 < Ea3 && Ea2 < Ea1)
    {
        printf("Best Approximation is :%2f\n",approx_val2);
    }
    else
    {
        printf("Best Approximation is :%2f\n",approx_val3);
    }
    
    return 0;
}