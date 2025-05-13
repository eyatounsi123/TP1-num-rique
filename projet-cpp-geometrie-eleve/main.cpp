#include "draw.hpp"
#include "point.hpp"
#include "shapes/triangle.hpp"
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

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
	 Triangle t(points.at(0), points.at(1), points.at(2));
    
	double p = t.perimeter();
    double expectedP = 100.0 + 100.0 + 100.0 * std::sqrt(2.0);
    assert(std::abs(p - expectedP) < 1e-6);

    // Test area
    double a = t.area();
    double expectedA = 100.0 * 100.0 / 2.0;  // 100×100
    assert(std::abs(a - expectedA) < 1e-6);

	 Point g = t.center();
    double expectedXg = (0.0 + 100.0 + 100.0) / 3.0;  // ≈ 66.666667
    double expectedYg = (0.0 +   0.0 + 100.0) / 3.0;  // ≈ 33.333333
    assert(std::abs(g.x - expectedXg) < 1e-6);
    assert(std::abs(g.y - expectedYg) < 1e-6);

    //  teste Translate 
    Point shift(10, -20);
    t.translate(shift);
	
    // Apres translation A=(10,-20), B=(110,-20), C=(110,80)
	
    Point A1 = t.center(); 
    double newXg = (10.0 + 110.0 + 110.0) / 3.0;
    double newYg = (-20.0 + -20.0 + 80.0) / 3.0;
    assert(std::abs(A1.x - newXg) < 1e-6);
    assert(std::abs(A1.y - newYg) < 1e-6);
	
	 t.draw();
	 
	 // Resize
    t = Triangle(points.at(0), points.at(1), points.at(2));
    Point G0 = t.center();
    double dA0 = points.at(0).distance(G0);
    t.resize(2.0);
    // distance de G0 doit etre doubler
    Point A_scaled = t.center(); 
    double dA1 = t.A.distance(G0);
    assert(std::abs(dA1 - 2.0 * dA0) < 1e-6);

   // Rotation à 90° autour de l'origine
   t = Triangle(Point(0,0), Point(3,0), Point(0,4));
     t.rotate(acos(-1.0) / 2.0);
     // B(3,0) → (0,3)
	assert(std::abs(t.B.x - 0.0) < 1e-6);
	
	 //C(0,4) → (–4,0)
	assert(std::abs(t.C.x + 4.0) < 1e-6);
	assert(std::abs(t.C.y - 0.0) < 1e-6);
	


    // Equals
    Triangle t2(Point(0,0), Point(100,0), Point(100,100));
    assert(t2.equals(Triangle(Point(0,0), Point(100,0), Point(100,100))));
    assert(t2.equals(Triangle(Point(100,0), Point(0,0), Point(100,100))));

    // isRightAngled
    Triangle rt(Point(0,0), Point(3,0), Point(0,4));
    assert(rt.isRightAngled());
    assert(!Triangle(Point(0,0), Point(1,1), Point(2,2)).isRightAngled());

    // isEquilateral
    //double h = std::sqrt(3.0);
    Triangle eq(Point(0,0), Point(2, 0), Point(1,1.74));
    assert(eq.isEquilateral());

    // isIsoceles
    Triangle iso(Point(0,0), Point(2,0), Point(1,2));
    assert(iso.isIsoceles());
    assert(!rt.isIsoceles());

    // Inscribed circle
    Triangle t345(Point(0,0), Point(3,0), Point(0,4));
    Circle ins = t345.inscribedCircle();
    assert(std::abs(ins.radius - 1.0) < 1e-6);
    assert(std::abs(ins.center.x - 1.0) < 1e-6);
    assert(std::abs(ins.center.y - 1.0) < 1e-6);

    // Circumscribed circle
    Circle circ = t345.circumscribedCircle();
    assert(std::abs(circ.radius - 2.5) < 1e-6);
    assert(std::abs(circ.center.x - 1.5) < 1e-6);
    assert(std::abs(circ.center.y - 2.0) < 1e-6);

    std::cout << "All tests passed."<<std::endl;
	 
	
	
	
	
	return 0;
}
