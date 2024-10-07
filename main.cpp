#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <memory>
#include <algorithm>

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
        cout << "\033[31m" << "Circle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << "\033[0m" << endl;
        cout << "\033[31m    ****    \033[0m" << endl;
        cout << "\033[31m  **    **  \033[0m" << endl;
        cout << "\033[31m *        * \033[0m" << endl;
        cout << "\033[31m*          *\033[0m" << endl;
        cout << "\033[31m*          *\033[0m" << endl;
        cout << "\033[31m *        * \033[0m" << endl;
        cout << "\033[31m  **    **  \033[0m" << endl;
        cout << "\033[31m    ****    \033[0m" << endl;
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
        cout << "\033[34m" << "Rectangle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << "\033[0m" << endl;
        cout << "\033[34m+--------+\033[0m" << endl;
        cout << "\033[34m|        |\033[0m" << endl;
        cout << "\033[34m|        |\033[0m" << endl;
        cout << "\033[34m|        |\033[0m" << endl;
        cout << "\033[34m|        |\033[0m" << endl;
        cout << "\033[34m|        |\033[0m" << endl;
        cout << "\033[34m+--------+\033[0m" << endl;
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
        cout << "\033[32m" << "Right Triangle - Area: " << getArea() << ", Perimeter: " << getPerimeter() << "\033[0m" << endl;
        cout << "\033[32m*        \033[0m" << endl;
        cout << "\033[32m**       \033[0m" << endl;
        cout << "\033[32m* *      \033[0m" << endl;
        cout << "\033[32m*  *     \033[0m" << endl;
        cout << "\033[32m*****\033[0m" << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<RightTriangle>(3, 4));

    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        cout << "\033[1;36m"; // Bright cyan color
        (*it)->print();
        cout << "\033[0m" << endl; // Reset color
    }

    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        cout << "\033[33mArea: " << (*it)->getArea() << ", Perimeter: " << (*it)->getPerimeter() << "\033[0m" << endl;
    }

    for_each(shapes.begin(), shapes.end(), [](const auto& shape) {
        cout << "\033[35mShape - Area: " << shape->getArea() << "\033[0m" << endl;
    });

    return 0;
}
