#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int main()
{
    string paragraph;
    cout<<"Enter your input : ";
    getline(cin,paragraph);

    map<string,int>freq;
    stringstream obj(paragraph);
    string Count;

    while(obj>>Count)
    {
        freq[Count]++;
    }

    for(auto &it : freq)
    {
        cout<<it.first<<" : "<<it.second<<endl;
    }

    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
}
