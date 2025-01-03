#include<stdio.h>
int main()
{
    int number1,number2,i=1,lcm;
    printf("Enter the first number:");
    scanf("%d",&number1);

    printf("Enter the first number:");
    scanf("%d",&number2);

    int greater = (number1>number2) ? number1 : number2;

    while(1)
    {
        if(i%number1==0 && i%number2==0)
        {
            lcm = i;
            break;
        }
        i++;
    }
    printf("The lcm of %d and %d is %d",number1,number2,lcm);
    printf("\n\nCreated by Jashkumar:24CE004");
}
