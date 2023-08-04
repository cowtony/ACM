#include <iostream>

using namespace std;

class Shape {
public:
    //virtual double getCircumference();
    virtual double getArea();
    //virtual void enlargeSize(double factor);
};

class Circle : public Shape {
public:
    double getArea() override {
        return 3.14 * radius_ * radius_;
    }
    //double getCircumference() override {}
private:
    double radius_ = 5;
};

int main () {
    Shape* myShape = new Circle;
    cout << myShape->getArea() << endl;
}