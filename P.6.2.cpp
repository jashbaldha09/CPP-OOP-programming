#include <iostream>
using namespace std;

class Marker {
private:
    int x;
    int y;

public:
    Marker(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    void moveX(int dx) {
        x += dx;
    }

    void moveY(int dy) {
        y += dy;
    }

    void showPosition() {
        cout << "Marker is at: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x, y, moveX, moveY;

    cout << "Enter initial X coordinate: ";
    cin >> x;
    cout << "Enter initial Y coordinate: ";
    cin >> y;

    Marker* ptr = new Marker(x, y);

    ptr->showPosition();

    cout << "Enter how much to move in X direction: ";
    cin >> moveX;
    ptr->moveX(moveX);

    cout << "Enter how much to move in Y direction: ";
    cin >> moveY;
    ptr->moveY(moveY);

    ptr->showPosition();

    delete ptr;
    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;

    return 0;
}

