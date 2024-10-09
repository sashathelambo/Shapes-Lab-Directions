#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <memory>
#include <algorithm>
#include <typeinfo>
#include <iomanip>

using namespace std;
class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    void print() const override {
        cout << "Circle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void print() const override {
        cout << "Rectangle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void print() const override {
        cout << "Square - Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

class RightTriangle : public Shape {
private:
    double base;
    double height;

public:
    RightTriangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {
        return 0.5 * base * height;
    }

    double getPerimeter() const override {
        double hypotenuse = sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }

    void print() const override {
        cout << "Right Triangle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

class IsoscelesRightTriangle : public RightTriangle {
public:
    IsoscelesRightTriangle(double side) : RightTriangle(side, side) {}

    void print() const override {
        cout << "Isosceles Right Triangle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

void printAreaToScreen(Shape *s) {
    string shapeName = typeid(*s).name();
    size_t colonPos = shapeName.find_last_of(':');
    if (colonPos != string::npos) {
        shapeName = shapeName.substr(colonPos + 1);
    }
    cout << "The area of the " << shapeName << " is " << fixed << setprecision(2) << s->getArea() << endl;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<RightTriangle>(3, 4));
    shapes.push_back(make_unique<Square>(5));
    shapes.push_back(make_unique<IsoscelesRightTriangle>(4));

    for (const auto& shape : shapes) {
        shape->print();
    }

    for (const auto& shape : shapes) {
        cout << "Area: " << shape->getArea() << ", Perimeter: " << shape->getPerimeter() << "\n";
    }

    for_each(shapes.begin(), shapes.end(), [](const auto& shape) {
        cout << "Shape - Area: " << shape->getArea() << "\n";
    });

    for (const auto& shape : shapes) {
        printAreaToScreen(shape.get());
    }

    return 0;
}
