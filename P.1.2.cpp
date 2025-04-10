#include<iostream>
using namespace std;

class invertory
{
public:
    int ID,quantity,price;
    string name;

    void addproduct()
    {
        cout<<"Enter your ID : "<<endl;
        cin>>ID;

        cout<<"Enter the quantity : "<<endl;
        cin>>quantity;

        cout<<"Enter price of product : "<<endl;
        cin>>price;

        cout<<"Enter product name : "<<endl;
        cin>>name;
    }
};

int main()
{
    invertory management[20];
    int choice,n=0;
    cout<<"Enter 1 to add product"<<endl;
    cout<<"Enter 2 to add quantity"<<endl;
    cout<<"Enter 3 to calculate the total values of all product"<<endl;
    cout<<"Enter 4 to Exit"<<endl;

    while(1)
    {
        jash:
        cout<<endl<<"Enter here: ";
        cin>>choice;
        cout<<endl;

        if(choice==1)
        {
            int amount;
            cout<<"Enter the numbers of products : ";
            cin>>amount;

            for(int i=1 ; i<=amount ; i++)
            {
                cout<<"Enter the detail for product "<<(n+1)<<endl;
                management[n].addproduct();
                n++;
            }
           // break;
        }

        else if(choice==2)
        {
            int check_id,quantity;
            bool found = false;
            cout<<"Enter your ID to update quantity : ";
            cin>>check_id;

            for(int j=0 ; j<n ; j++)
            {
                if(management[j].ID == check_id)
                {
                    cout<<"your quantity is "<<management[j].quantity<<endl;
                    cout<<"Enter your quantity : ";
                    cin>>quantity;

                    management[j].quantity += quantity;
                    cout<<"your quantity successfully updated!"<<endl<<"Your quantity is "<<management[j].quantity<<endl;
                    found = true;
                }
            }

            if(found==false)
            {
                cout<<"invalid ID"<<endl;
            }
        }

        else if(choice==3)
        {
            int value=0;
            for(int k=0 ; k<n ; k++)
            {
                value += management[k].price*management[k].quantity;
            }
            cout<<"Total value is "<<value<<endl;
        }

        else if(choice==4)
        {
            cout<<"Exit the system!!"<<endl;
            break;
        }

        else
        {
            cout<<"Enter the valid value"<<endl;
            goto jash;
        }
    }
    endl<<cout<<"Created by Jashkumar - 24CE004"<<endl;
}
