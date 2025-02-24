#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Inventory
{
    string ItemName;
    int ItemId,ItemPrice,ItemQuantity,ItemTotal=0;

    public:
    bool SearchID(int Id)
    {
        if(Id == ItemId)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void NewItem(int Id,int Price,string Name,int Quantity)
    {
        ItemId = Id;
        ItemPrice = Price;
        ItemName = Name;
        ItemQuantity = Quantity;
    }

    void SellQuantity(int Quantity)
    {
        if(Quantity <= ItemQuantity)
        {
            ItemQuantity -= Quantity;
        }

        else
        {
            cout<<"Not Enough Stock"<<endl;
        }
    }

    void AddQuantity(int Quantity)
    {
        ItemQuantity += Quantity;
    }

    void GenerateBill()
    {
        ItemTotal = ItemQuantity*ItemPrice;
        cout<<left<<setw(10)<<ItemId<<setw(15)<<ItemName<<right<<setw(10)<<ItemQuantity<<setw(10)<<ItemPrice<<setw(10)<<ItemTotal<<endl;
    }

    int GetTotal()
    {
        return ItemQuantity*ItemPrice;
    }
};

int main()
{
    int Choice1,Id,Price,Quantity,n=0,i=0;
    string Name;

    Inventory Stock[20];

    cout<<"----------------Welcome To The System----------------"<<endl;
    cout<<"1.To sell the stock"<<endl;
    cout<<"2.To Add the product"<<endl;
    cout<<"3.To Update the product"<<endl;
    cout<<"4.To Generate bill of inventory"<<endl;
    cout<<"5.To exit the system"<<endl;
    while(Choice1!=5)
    {
        bool Verify = false;
        cout<<endl<<"Enter your choice : ";
        cin>>Choice1;

        switch(Choice1)
        {
        case 1:
            cout<<"Enter ID number : ";
            cin>>Id;

            for(i=0 ; i<n ; i++)
            {
                if(Stock[i].SearchID(Id)== true)
                {
                    Verify = true;
                    break;
                }
            }

            if(Verify == true)
            {
                cout<<"Enter your quantity to buy: ";
                cin>>Quantity;
                Stock[i].SellQuantity(Quantity);
            }

            else
            {
                cout<<"Enter valid ID"<<endl;
            }
        break;

        case 2:
            cout<<"Enter ID number : ";
            cin>>Id;

            for(i=0 ; i<n ; i++)
            {
                if(Stock[i].SearchID(Id))
                {
                    Verify = true;
                    break;
                }
            }

            if(Verify == true)
            {
                cout<<"Enter valid choice"<<endl;
            }

            else
            {
                cout<<"Enter the price : ";
                cin>>Price;
                cin.ignore();

                cout<<"Enter the name : ";
                getline(cin,Name);

                cout<<"Enter the quantity : ";
                cin>>Quantity;

                Stock[i].NewItem(Id,Price,Name,Quantity);
                n++;
            }
            break;

        case 3:
            cout<<"Enter ID number : ";
            cin>>Id;

            for(i=0 ; i<n ; i++)
            {
                if(Stock[i].SearchID(Id))
                {
                    Verify = true;
                    break;
                }
            }

            if(Verify == true)
            {
                cout<<"Enter your quantity : ";
                cin>>Quantity;
                Stock[i].AddQuantity(Quantity);
            }

            else
            {
                cout<<"Enter valid choice"<<endl;
            }
            break;

        case 4:
            {
                int GrandTotal = 0;
                cout<<endl<<"-------------------------------BILL-------------------------------"<<endl;
                cout<<left<<setw(10)<<"ID"<<setw(15)<<"Name"<<right<<setw(10)<<"Quantity"<<setw(10)<<"Price"<<setw(10)<<"Total"<<endl;
                cout<<"------------------------------------------------------------------"<<endl;
                for(int i=0 ; i<n ; i++)
                {
                    Stock[i].GenerateBill();
                    GrandTotal += Stock[i].GetTotal();
                }
                cout<<"------------------------------------------------------------------"<<endl;
                cout<<left<<setw(45)<<"BILL"<<right<<setw(10)<<GrandTotal;
                break;
            }

        case 5:
            {
                cout<<"Exit the system!!!"<<endl;
                cout<<endl<<"Created by Jashkumar baldha - 24CE004"<<endl;
                return 0;
            }
        }
    }
}
