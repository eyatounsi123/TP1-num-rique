#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include <cmath>
#include <vector>

Circle::Circle(double r, Point c) : radius(r), center(c) {};


double Circle::circumference() {
	return 2 * 3.14159265358979323846* radius;
}
double Circle::area(){
	return 3.14159265358979323846* radius * radius;
	
}
void Circle::draw() {
	std::vector<Point> points;
		const int steps = 100; 
		const double angle_step = 2 *3.14159265358979323846/ steps;

		for (int i = 0; i <= steps; ++i) {
			double angle = i * angle_step;
			double x = center.x + radius * cos(angle);
			double y = center.y + radius * sin(angle);
			points.push_back(Point(x, y));
    }
	draw_picture(points);
}	
	
void Circle::resize(double ratio) {
    radius = radius*ratio;
}
void Circle::translate(Point T){
	    center.x += T.x;
		center.y += T.y;
}
bool Circle::equals(Circle circle) {
	bool test = radius == circle.radius;
	return test;
}