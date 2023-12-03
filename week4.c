#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double CalArea() = 0;
    virtual double CalPeri() = 0;
    virtual void display() = 0;
    virtual int calAngleSum() = 0;
};

class Hexagon : public Shape
{
private:
    double s;

public:
    Hexagon(int s)
    {
        this->s = s;
    }
    double CalArea()
    {
        return 1.5 * 1.732 * s;
    }
    double CalPeri()
    {
        return 6 * s;
    }
    void display()
    {
        cout << "\nThe area is " << CalArea();
        cout << "\nThe Angle Sum is " << calAngleSum();
        cout << "\nThe Area is " << CalArea();
    }
    int calAngleSum()
    {
        return 6 * (2 * 120);
    }
};

class Square : public Shape
{
private:
    double s;

public:
    Square(int s)
    {
        this->s = s;
    }
    double CalArea()
    {
        return 2 * s;
    }
    double CalPeri()
    {
        return 4 * s;
    }
    void display()
    {
        cout << "\nThe Area is " << CalArea();
        cout << "\nThe Primeter is " << CalPeri();
    }
    int calAngleSum()
    {
        return 360;
    }
};

int main()
{
    Shape *s = new Hexagon(8);
    Shape *s2 = new Square(8 + 1);
    int op = 1;
    while (op == 1 || op == 2)
    {
        cout << "Enter 1 for Display Hexagon 2 for Square\n";
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            s->display();
            break;
        case 2:
            s2->display();
            break;
        default:
            cout << "\nExist";
        }
    }
    return 0;
}


