#include<stdio.h>
#include<math.h>
int amstrong(int,int);
int main()
{
    int number,remainder1,remainder2,a,sum=0,length=0,original1,original2;
    printf("Enter your number:");
    scanf("%d",&number);

    original1 = number;
    original2 = number;

    while(original1>0)
    {
        remainder1 = original1%10;
        length++;
        original1/=10;
    }

    while(original2>0)
    {
        remainder2 = original2%10;
        a = amstrong(remainder2,length);
        sum += a;

        original2/=10;
    }
    printf("Your sum of %d is %d",number,sum);

    if(sum==number)
    {
        printf("\nYour number is amstrong number");
    }

    else
    {
        printf("\nYour number is not amstrong number");
    }
    printf("\n\nCreated by Jashkumar:24CE004");
}

int amstrong(int number,int length)
{
    int number1 = pow(number,length);
    return number1;
}
