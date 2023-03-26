#ifndef HELLO
#define HELLO

#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double weight;
    double height;
    static int num;

protected:
    int number;

public:
    int numA;
    Box(
    ) { num++; 
        cout << "构造函数" << endl;
        }
    ~Box() {
        cout << "xigou函数" << endl;
    }
    Box(double l, double w, double h)
    {
        length = l;
        weight = w;
        height = h;
    }
    virtual void buwhidqo();
    static int getNum() { return num; }
    void setLength(double l) { length = l; }
    // overload
    /* void setLength(double l, int h);
    void setLength(int l, double h); */
    void setWeight(double w) { weight = w; }
    void setHeight(double h) { height = h; }

    double getLength() const { return length; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }
};

class ObjectA : public Box
{
public:
    int buwhidao;
    ObjectA(){
        cout << "子类构造函数" << endl;
    }
    ~ObjectA(){
        cout << "子类xigou函数" << endl;
    }
    // surcharge override
    void setLength(double l)
    {
        cout << l << endl;
    }
    void setLength(double l, double h)
    {
    }
};

class ObjectB : protected Box
{
};

class ObjectC : private Box
{
private:
    int numA;

public:
    void setNum(int a)
    {
        numA = a;
    }
};

int Box::num = 0;

#endif