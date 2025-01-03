#include<stdio.h>
#include<math.h>
int main()
{
    int binary,decimal=0,octal[32],length1=0,length2=0,original1,remainder,j=0;
    printf("Enter your binary number:");
    scanf("%d",&binary);

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
    printf("%d",decimal);

    j=0;
printf("\n");
    while(binary>0)
    {

        printf("%d\t",binary);
        octal[j] = binary%8;
        binary /= 8;
        j++;
    }
    octal[j] = '\0';

    length2=0;
    for(j=0 ; octal[j]!='\0' ; j++)
    {
        length2++;
    }
    printf("\n%d",length2);

   for(j=0 ; j<length2 ; j++)
    {
        printf("%d\t",octal[j]);
    }
}
