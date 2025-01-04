#include<stdio.h>
#include<math.h>
int main()
{
    long long m,n,a;
    printf("Enter the m and n:");
    scanf("%lld %lld",&m,&n);

    printf("Enter the a:");
    scanf("%lld",&a);

    long long length = (long long)ceil((double)m/a);
    long long breadth = (long long)ceil((double)n/a);
    long long tiles = length*breadth;

    printf("Total will be %lld",tiles);
    printf("\n\nCreated by Jashkumar:24CE004");
}
