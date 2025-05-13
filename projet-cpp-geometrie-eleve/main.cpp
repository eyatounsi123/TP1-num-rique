#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>


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
	assert(std::abs(c.area() - 314.159265) < 0.001);
	assert(std::abs(c.circumference() - 62.831853) < 0.001);
    	c.draw();
	
	return 0;
}
