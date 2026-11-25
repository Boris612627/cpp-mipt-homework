#include <iostream>
#include "point.hpp"
using std::cout, std::endl;

class Circle
{
private:
	Point center;
	float radius;

public:
    Circle(){
        center = Point(0, 0);
        radius = 1.0f;
    }

    Circle(const Point& center, float radius){
        this->center = center;
        if(radius >= 0) this->radius = radius;
        else this->radius = 0;
    }

    Circle(const Circle& circle){
        this->center = circle.center;
        this->radius = circle.radius;
    }
    Point getCenter() const {return center;}
    float getRadius() const {return radius;}

    void setCenter(const Point& center) {this->center = center;}
    void setRadius(float radius){
        if(radius >= 0) this->radius = radius;
        else this->radius = 0;
    }

    float area() const{
        float pi = 3.14159265f;
        return pi*radius*radius;
    }

    float distance(const Point& p) const{
        float dist = center.distance(p);
        if (radius <= dist) return dist - radius;
        else return radius - dist; 
    }

    bool isColliding(const Circle& c) const{
        float dist = center.distance(c.center);
        float sumrad = c.radius + radius;
        if(sumrad >= dist) return true;
        else return false;
    }
    void move(const Point&p){
        setCenter(center + p);
    }
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;

	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
}
