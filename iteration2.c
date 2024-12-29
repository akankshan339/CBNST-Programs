
//f(x) = cos x - 3x +1 where  x = 1.0/3.0(cos x +1) 
//differention of x  = -sin x/3.0

//f(x) = 2x - log base 10 (x) -7 where  x = log base 10 (x) +7 / 2
//derivative of x = 1/ 2xlog base e 10 

#include<stdio.h>
#include<math.h>

float f(float x)
{
    //return cos(x) - 3*x +1;
    //return 2*x - log(10)*x -7;
    return x*x*x -x -1;
}
float g(float x)
{
   // return  x = 1.0/3.0 *(cos(x) +1) ;  
   //return (log10(x) + 7) / 2.0;
   return cbrt(x + 1);

}

float dq(float x)
{
    // return -sin(x)/3.0; 
    // return 1.0 / (2 * x * log(10));    //log(10) gives the natural logarithm of 10 to base e 
    return (1.0 / 3.0) * pow(x + 1, -2.0 / 3.0);

}
int main()
{
    int flag = 0, iter =0;
    float x0, x1,allowederr;
    do{
    printf("Enter the value of x0 :\n");
    scanf("%f", &x0);
    if(fabs(dq(x0)) < 1)    // Check if the derivative's absolute value is less than 1
    {
        flag =1;
    }
    else{
        printf("Case not satisfied change the function.\n");
    }
}while(flag != 1);

    printf("Enter Allowed Error : \n");
    scanf("%f", &allowederr);
do{
    iter++;
     // Compute the next approximation
        x1 = g(x0);
    
    if(fabs(x0 - x1) <= allowederr) //Check for convergence
    {
        flag =0;
        printf("Root of the equation is %f after %d iteration \n", x1, iter);
    }
    else{
        x0 = x1;    // Update x0 for the next iteration
    printf("%d iteration , value of x0 is %f , value of g(%f) is %f\n", iter, x0, x0, g(x0));
    }

}while(flag != 0);

    return 0;
}