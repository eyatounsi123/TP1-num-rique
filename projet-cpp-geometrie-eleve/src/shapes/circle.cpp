#include "point.hpp"
#include "shapes/circle.hpp"

Circle::Circle(double r, Point c) : radius(r), center(c) {};

<<<<<<< HEAD
=======


>>>>>>> 44830a8 (Deuxième commit)
double Circle::circumference() {
	return 2 * M_PI * radius;
}
double Circle::area(){
	return M_PI * radius * radius;
	
}
void Circle::draw() {
	std::vector<Point> points;
		const int steps = 100; 
		const double angle_step = 2 * M_PI / steps;

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
void Circle::translate((Point T){
	    center.x += T.x;
		center.y += T.y;
}
bool Circle::equals(Circle circle) {
	test = radius == circle.radius;
	return test;
<<<<<<< HEAD
}
=======
}
>>>>>>> 44830a8 (Deuxième commit)
