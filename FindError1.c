//deduce error  True Value root (2) =1.41421356237 approx val = 1.414
#include<stdio.h>
#include<math.h>

int main()
{
float absolute_err, relative_err, percentage_err;
float true_val, approxval;
printf("Enter true value\n");
scanf("%f", &true_val);
printf("Enter approximation value \n");
scanf("%f",& approxval);
absolute_err=fabs(true_val - approxval);    //to find absolute for floating nos
printf("Absolute error is = %f \n",absolute_err);
relative_err=absolute_err/true_val;
printf("Realtive error is = %f \n",relative_err);
percentage_err=relative_err * 100;
printf("Percentage error is = %f \n",percentage_err);
return 0;

}