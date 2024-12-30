#include<stdio.h>
int main()
{
    char str[30];
    int length=0;
    printf("Enter your string : ");
    gets(str);

    for(int i=0 ; str[i]!='\0' ; i++)
    {
        length++ ;
    }

    printf("\nThe length of the string is %d",length);
    printf("\n\nCreated by Jashkumar:24CE004");
}
