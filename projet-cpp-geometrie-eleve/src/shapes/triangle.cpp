#include "shapes/triangle.hpp"
#include "draw.hpp"
#include <cmath>
#include <vector>
#include "shapes/circle.hpp"


using namespace std;

Triangle::Triangle(Point P, Point Q, Point R)
    : A(P), B(Q), C(R) {}

double Triangle::perimeter() {
    return A.distance(B)
         + B.distance(C)
         + C.distance(A);
}

double Triangle::area() {
    double ux = B.x - A.x;
    double uy = B.y - A.y;
    double vx = C.x - A.x;
    double vy = C.y - A.y;
    double cross = ux * vy - uy * vx;
    return 0.5 * abs(cross);
}

Point Triangle::center() {
    double xg = (A.x + B.x + C.x) / 3.0;
    double yg = (A.y + B.y + C.y) / 3.0;
    return Point(xg, yg);
}

void Triangle::draw() {
    vector<Point> pts = { A, B, C, A };
    draw_picture(pts);
}

void Triangle::translate(Point T) {
    A.x += T.x;  A.y += T.y;
    B.x += T.x;  B.y += T.y;
    C.x += T.x;  C.y += T.y;
}

void Triangle::resize(double ratio) {
    Point G = center();
    A.x = G.x + ratio * (A.x - G.x);
    A.y = G.y + ratio * (A.y - G.y);
    B.x = G.x + ratio * (B.x - G.x);
    B.y = G.y + ratio * (B.y - G.y);
    C.x = G.x + ratio * (C.x - G.x);
    C.y = G.y + ratio * (C.y - G.y);
}



void Triangle::rotate(double angle) {
    auto rotate_point = [angle](Point& p) {
        double x_new = p.x * std::cos(angle) - p.y * sin(angle);
        double y_new = p.x * std::sin(angle) + p.y * cos(angle);
        p.x = x_new;
        p.y = y_new;
    };
    rotate_point(A);
    rotate_point(B);
    rotate_point(C);
}


bool Triangle::equals(Triangle triangle){
	double d1=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	double d2=sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
	double d3=sqrt((C.x-A.x)*(C.x-A.x)+(C.y-A.y)*(C.y-A.y));
	double dt1=sqrt((triangle.B.x-triangle.A.x)*(triangle.B.x-triangle.A.x)+(triangle.B.y-triangle.A.y)*(triangle.B.y-triangle.A.y));
	double dt2=sqrt((triangle.B.x-triangle.C.x)*(triangle.B.x-triangle.C.x)+(triangle.B.y-triangle.C.y)*(triangle.B.y-triangle.C.y));
	double dt3=sqrt((triangle.C.x-triangle.A.x)*(triangle.C.x-triangle.A.x)+(triangle.C.y-triangle.A.y)*(triangle.C.y-triangle.A.y));
	if((d1-dt1)<1e-6){
		if((d2-dt2)<1e-6){
			if((d3-dt3)<1e-6){
				return true;
			}
		}
		if((d2-dt3)<1e-6){
			if((d3-dt2)<1e-6){
				return true;
			}
		}
	}else{
		if((d1-dt2)<1e-6){
			if((d2-dt1)<1e-6){
				if((d3-dt3)<1e-6){
					return true;
				}
			}
			if((d2-dt3)<1e-6){
				if((d3-dt1)<1e-6){
					return true;
				}
			}
		}else{
		if((d1-dt3)<1e-6){
			if((d2-dt1)<1e-6){
				if((d3-dt2)<1e-6){
					return true;
				}
			}
			if((d2-dt2)<1e-6){
				if((d3-dt1)<1e-6){
					return true;
				}
			}
		}
	
		}
	}

	return false;

}

bool Triangle::isRightAngled(){
	double d1=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	double d2=sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
	double d3=sqrt((C.x-A.x)*(C.x-A.x)+(C.y-A.y)*(C.y-A.y));
	if(d1>d2 and d1>d3){
		if(d1*d1==d2*d2+d3*d3){
			return true;
		}
		else{
			return false;
		}
	}
	if(d2>d1 and d2>d3){
		if(d2*d2==d1*d1+d3*d3){
			return true;
		}
		else{
			return false;
		}
	}
	if(d3>d2 and d3>d1){
		if(d3*d3==d2*d2+d1*d1){
			return true;
		}
		else{
			return false;
		}
	}
	  return false;
}

bool Triangle::isEquilateral(){
	double d1=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	double d2=sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
	double d3=sqrt((C.x-A.x)*(C.x-A.x)+(C.y-A.y)*(C.y-A.y));
	if((d1-d2)<1e-6 and (d1-d3)<1e-6 and (d2-d3)<1e-6){
		return true;
	}
	return false;
}

bool Triangle::isIsoceles(){
	double d1=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	double d2=sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
	double d3=sqrt((C.x-A.x)*(C.x-A.x)+(C.y-A.y)*(C.y-A.y));
	if(d1==d2){
		return true;
	}
	if(d1==d3){
		return true;
	}
	if(d2==d3){
		return true;
	}
	return false;
}

Circle Triangle::inscribedCircle() {
    double a = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y)); // BC
    double b = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y)); // AC
    double c = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)); // AB
    double p = a + b + c;

    double x = (a * A.x + b * B.x + c * C.x) / p;
    double y = (a * A.y + b * B.y + c * C.y) / p;

    double r = 2 * area() / p;
    return Circle(r, Point(x, y));
}


Circle Triangle::circumscribedCircle() {
    double x1 = A.x, y1 = A.y;
    double x2 = B.x, y2 = B.y;
    double x3 = C.x, y3 = C.y;

    double D = 2 * (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    double Ux = ((x1*x1 + y1*y1)*(y2 - y3) + (x2*x2 + y2*y2)*(y3 - y1) + (x3*x3 + y3*y3)*(y1 - y2)) / D;
    double Uy = ((x1*x1 + y1*y1)*(x3 - x2) + (x2*x2 + y2*y2)*(x1 - x3) + (x3*x3 + y3*y3)*(x2 - x1)) / D;

    Point O(Ux, Uy); // Centre du cercle circonscrit
    double r = std::sqrt((O.x - A.x)*(O.x - A.x) + (O.y - A.y)*(O.y - A.y));
    return Circle(r, O);
}
