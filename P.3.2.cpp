#include<iostream>
using namespace std;

int RecursiveSum(int *arr,int n)
{
    int sum = 0;

    if(n==0)
    {
        return sum;
    }

    else
    {
        sum += arr[n-1] + RecursiveSum(arr,n-1);
    }
}

int ItretiveSum(int *arr,int n)
{
    int sum = 0;
    for(int j=0 ; j<n ; j++)
    {
        sum += arr[j];
    }

    return sum;
}
int main()
{
    int n;

    cout<<"Enter the size of the Array : ";
    cin>>n;

    int *arr = new int[n];

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the element number "<<i+1<<" :";
        cin>>arr[i];
    }

    cout<<"Sum using Recursive function is : "<<RecursiveSum(arr,n)<<endl;

    cout<<"Sum using Itretive function is : "<<ItretiveSum(arr,n)<<endl;
    delete[] arr;

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;

}
