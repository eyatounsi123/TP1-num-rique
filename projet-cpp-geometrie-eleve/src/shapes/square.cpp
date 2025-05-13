#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <cmath>
#include <vector>
using namespace std;
Square::Square(Point P, Point R) : A(P), C(R) {};
double Square::side(){
    double a=A.distance(C)/sqrt(2);
    return a;
}
double Square::perimeter(){
    return side()*4;
}
double Square::area(){
    return side()*side();    
}
Point Square::center(){
    Point p((A.x+C.x)/2,(A.y+C.y)/2);
    return p;
}

void Square::draw() {
    double dx=(C.x-A.x)/2.0;
    double dy=(C.y-A.y)/2.0;
    Point B(center().x-dy,center().y+dx);
    Point D(center().x+dy,center().y-dx);

    std::vector<Point> points{A,B,C,D,A}; 
    draw_picture(points);
}

void Square::translate(Point T) {
    A.x+=T.x;
    A.y+=T.y;
    C.x+=T.x;
    C.y+=T.y;
}
void Square::resize(double ratio) {
    Point O=center(); 
    A.x=O.x+(A.x-O.x)*ratio;
    A.y=O.y+(A.y-O.y)*ratio;
    C.x=O.x+(C.x-O.x)*ratio;
    C.y=O.y+(C.y-O.y)*ratio;
}

void Square::rotate(double angle) {
    Point c=center(); 
    A.x=A.x-c.x;
    C.x=C.x-c.x;
    A.y=A.y-c.y;
    C.y=C.y-c.y;
        
    Point new_A(A.x*cos(angle)-A.y*sin(angle),A.x*sin(angle)+A.y*cos(angle));
    Point new_C(C.x*cos(angle)-C.y*sin(angle),C.x*sin(angle)+C.y*cos(angle));
    
    A.x=new_A.x+c.x;
    A.y=new_A.y+c.y;
    C.x=new_C.x+c.x;
    C.y=new_C.y+c.y;

}


bool Square::equals(Square square){
	return side()==square.side();
}
Circle Square::inscribedCircle(){
    Circle c(side()/2,center());
    return c;
}
Circle Square::circumscribedCircle(){
    Circle c(A.distance(C)/2,center());
    return c;
}

