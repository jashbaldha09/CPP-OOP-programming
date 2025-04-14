#include <iostream>
#include <vector>
using namespace std;

class Fuel
{
protected:
    string TFuel;

public:
    Fuel() {}

    Fuel(string FuelType)
    {
        TFuel = FuelType;
    }
};

class Brand {
protected:
    string TBrandName;

public:
    Brand() {}

    Brand(string BrandName)
    {
        TBrandName = BrandName;
    }
};

class Car : public Fuel, public Brand {
public:
    Car() {}

    Car(string FuelType, string BrandName) : Fuel(FuelType), Brand(BrandName) {}

    void DisplayCarInfo()
    {
        cout << "Fuel Type: " << TFuel << endl;
        cout << "Brand    : " << TBrandName << endl;
    }
};

int main() {
    vector<Car> cars;
    string FuelType, BrandName;

    cout<<"Enter to 'stop' to exit"<<endl;
    while (true) {
        cout << "Enter fuel type : ";
        cin >> FuelType;
        if (FuelType == "stop")
            break;

        cout << "Enter brand name: ";
        cin >> BrandName;

        cars.emplace_back(FuelType, BrandName);
        cout << endl;
    }

    cout << "\n--- Service Queue: Car Details ---\n";
    for (int i = 0; i < cars.size(); i++) {
        cout << "\nCar " << i + 1 << ":\n";
        cars[i].DisplayCarInfo();
    }

    cout << "\nCreated by Jashkumar : 24CE004\n";
}
