#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <cassert>
#include <cmath>

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

	    Square s(Point(0, 0), Point(100, 100));

    	double expected_side = sqrt(20000)/sqrt(2);
    	assert(std::abs(s.side() - expected_side) < 1e-6);
    	assert(std::abs(s.perimeter() - 4 * expected_side) < 1e-6);
    	assert(std::abs(s.area() - expected_side * expected_side) < 1e-6);

    	Point c = s.center();
    	assert(std::abs(c.x - 50.0) < 1e-6);
    	assert(std::abs(c.y - 50.0) < 1e-6);

    
    	s.translate(Point(10, 10));
    	Point newCenter = s.center();
    	assert(std::abs(newCenter.x - 60.0) < 1e-6);
    	assert(std::abs(newCenter.y - 60.0) < 1e-6);

    
    	double old_side = s.side();
    	s.resize(2);
    	assert(std::abs(s.side() - old_side * 2) < 1e-6);

    
   	 Square s2(Point(0, 0), Point(100, 100));
    	s2.translate(Point(10, 10));
    	s2.resize(2);
    	assert(s.equals(s2));
	s.draw();
	return 0;
}
