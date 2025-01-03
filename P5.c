#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,root1,root2;
    printf("The Quadratic equation is aX^2+bX+c");

    jash:
    printf("\nEnter the value of a:");
    scanf("%f",&a);

    if(a==0)
    {
        goto jash;
    }

    printf("Enter the value of b:");
    scanf("%f",&b);

    printf("Enter the value of c:");
    scanf("%f",&c);

    d = b*b - 4*a*c;

    if(d>0)
    {
        printf("\nThe roots are real and different");

        root1 = (-b + sqrt(d))/2*a;
        root2 = (-b - sqrt(d))/2*a;

        printf("The roots are:%.2f and %.2f",root1,root2);
    }

    else if(d==0)
    {
        printf("\nThe roots are real and same");

        root1 = (-b + sqrt(d))/2*a;
        root2 = (-b - sqrt(d))/2*a;

        printf("The roots are:%.2f and %.2f",root1,root2);
    }

    else
    {
        printf("\nThe roots are imaginary and different");

        root1 = (sqrt(-d))/2*a;
        root2 = (sqrt(-d))/2*a;

        printf("The roots are:%.2f+%.2fi and %.2f-%.2fi",-b/2,root1,-b/2,root2);
    }
    printf("\n\nCreated by Jashkumar:24CE004");
}
