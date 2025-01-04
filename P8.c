#include<stdio.h>
int main()
{
    int arr[3][3],sum1=0,sum2=0,sum3=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            printf("Enter arr[%d][%d]:",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    sum1 = arr[0][0]+arr[1][0]+arr[2][0];
    sum2 = arr[0][1]+arr[1][1]+arr[2][1];
    sum3 = arr[0][2]+arr[1][2]+arr[2][2];

    if(sum1==0 && sum2==0 && sum3==0)
    {
        printf("Yes");
    }

    else
    {
        printf("No");
    }

    printf("\n\nCreated by Jashkumar:24CE004");
}
