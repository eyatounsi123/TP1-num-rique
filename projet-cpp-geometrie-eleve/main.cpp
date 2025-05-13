#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <cmath>
#include <cassert>
bool are_equal(double a, double b, double epsilon = 1e-6) {
		return std::abs(a - b) < epsilon;
}



int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	
	
    
    Point centre(0, 0);
    Circle c(10, centre);

    // aire
    assert(are_equal(c.area(), 314.159265));

    // circonférence
    assert(are_equal(c.circumference(), 62.831853));

    // translate
    c.translate(Point(10, 5));
    assert(are_equal(c.center.x, 10));
    assert(are_equal(c.center.y, 5));

    //  resize
    c.resize(2);
    assert(are_equal(c.radius, 20));
    assert(are_equal(c.area(), 1256.63706));
	// Test égalité
    Circle c2(20, Point(10, 5));
    assert(c.equals(c2));

    // Dessin du cercle 
    c.draw();
	return 0;
}
