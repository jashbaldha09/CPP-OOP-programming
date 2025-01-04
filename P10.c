#include<stdio.h>
int main()
{
    int number,sum,original;
    printf("Enter the number:");
    scanf("%d",&number);

    original = number;

    for(int i=1 ; i<original ; i++)
    {
        if(original%i==0)
        {
            sum+=i;
        }
    }

    printf("The sum is %d",sum);
    if(sum==number)
    {
        printf("\nThe number is perfect number");
    }

    else
    {
        printf("\nThe number is not perfect");
    }
    printf("\n\nCreated by Jashkumar:24CE004");
}
