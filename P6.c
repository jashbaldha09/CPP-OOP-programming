#include<stdio.h>
#include<math.h>
int main()
{
    int binary,decimal=0,octal[32],length1=0,original1,remainder,j=0;
    printf("Enter your binary number:");
    scanf("%d",&binary);

    //convert binary to decimal
    original1 = binary;
    while(original1>0)
    {
        remainder = original1%10;
        length1++;
        original1 /= 10;
    }

    original1 = binary;

    for(int i=0 ; i<length1 ; i++)
    {
        remainder = original1%10;
        decimal += remainder*pow(2,i);
        original1 /= 10;
    }
    printf("The decimal number is : %d",decimal);

    //convert decimal to octal
    j=0;
    printf("\n");
    while(decimal>0)
    {
        octal[j] = decimal%8;
        decimal /= 8;
        j++;
    }
    //octal[j] = '\0';

    printf("The octal number is : ");
    for (int i = j - 1; i >= 0; i--)
    {
        printf("%d", octal[i]);
    }
    printf("\n\nCreated by Jashkumar:24CE004");
}
