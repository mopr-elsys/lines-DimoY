#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001) {
    return abs(d2 - d1) < eps;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x;
    in >> p.y;

    return in;
}

struct Line {
    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {}

    Line(const Point& p1, const Point& p2) {
        this->A =-p2.y+p1.y;
        this->B = p2.x-p1.x;
        this->C = this->B*p1.y-this->A*p1.x;
    }

    bool parallel(const Line& other) {
        if(other.A == 0){
            if(this->A == 0){
                return true;
            }
            return false;
        }
        if(other.B == 0){
            if(this->B == 0){
                return true;
            }
            return false;
        }
        if ((this->A/other.A == this->B/other.B) && (this->A/other.A != this->C/other.C)){
            return true;
        }
        return false;;
    }

    Line parallel(const Point& p) {
        double c = -this->A*p.x - this->B*p.y;
        return Line(this->A,this->B,c);
    }

    bool perpendicular(const Line& other) const {
        if(other.A == 0){
            if(this->B == 0){
                return true;
            }
            return false;
        }
        if(other.B == 0){
            if(this->A == 0){
                return true;
            }
            return false;
        }
        if((this->A/this->B) == (-(other.B/other.A))){
            return true;
        }
        return false;
    }

    Line perpendicular(const Point& p) {
        double c = +this->B*p.x-this->A*p.y;
        return Line(-this->B,this->A,c);
    }

    void print(ostream& out) const {
        if(this->C == 0){
           out<< A << "x + "<< B<< "y + -"<< C<< " = 0";
        }
        out<< A << "x + "<< B<< "y + "<< C<< " = 0";
    }
};

ostream& operator<<(ostream& out, const Line& l) {
    l.print(out);
    return out;
}

istream& operator>>(istream& in, Line& l) {
    in >> l.A;
    in >> l.B;
    in >> l.C;

    return in;
}
