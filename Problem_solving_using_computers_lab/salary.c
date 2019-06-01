#include <stdio.h>
int main ()
{
double sal,tax;
printf ("Enter the salary");
scanf ("%lf",&sal);
if (sal>=1000000)
    tax=sal*0.3;
else if (sal<1000000&&sal>=500000)
    tax=sal*0.2;
else if (sal<500000&&sal>=200000)
    tax=sal*0.1;
else
    tax=0;
printf ("The tax is %lf",tax);
return 0;
}
