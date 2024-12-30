#include<stdio.h>
#include<ctype.h>
int main()
{
    char str[30];
    printf("Enter your string : ");
    gets(str);

    for(int i=0 ; str[i]!='\0' ; i++)
    {
        if(islower(str[i]))
        {
            str[i]= toupper(str[i]);
        }

        else if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }

    printf("\nThe new string is :");
    puts(str);
    printf("\n\nCreated by Jashkumar:24CE004");
}
