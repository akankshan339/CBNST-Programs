//f(x) = x^3 -4x- 9 where x = (4x +9)^1/3 or x = 1/4(x^3 - 9)
//differention of x  = 1/3 (4x+9)^ -2/3
//f(x) = cos x - 3x +1 where  x = 1.0/3.0(cos x +1) 
//differention of x  = -sin x/3.0
#include<stdio.h>
#include<math.h>

float f(float x)
{
    return pow(x, 3) - 4*x - 9; //f(x) =x^3 -4x- 9

}
float g(float x)
{
    return pow ((4* x +9 ), 1.0/3.0);   //x = (4x +9)^1/3 
}

float dq(float x)
{
    return (1.0/3.0) * pow((4*x + 9), -2.0/3.0) *4;  //differention of x  = 1/3 (4x+9)^ -2/3 or derivative of g(x)
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