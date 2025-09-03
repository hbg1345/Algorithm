#include<set>
#include<iostream>
#include <set>

#define pii pair<int, int>

using namespace std;

struct Point{
    int x, y;
    Point(int _x, int _y): x(_x), y(_y) {}
    Point subtract(Point p) {
        return Point(this->x-p.x, this->y-p.y);
    }
    Point add(Point p) {
        return Point(this->x+p.x, this->y+p.y);
    }
    int dot(Point p) {
        int a = this->x*p.x;
        int b = this->y*p.y;
        return abs(a+b);
    }

};
void _main(int tnum) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    set<pii> st = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
    Point p1(x1, y1);
    Point p2(x2, y2);
    Point p3(x3, y3);
    Point p4(x4, y4);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Point p21(x1, y1);
    Point p22(x2, y2);
    Point p23(x3, y3);
    Point p24(x4, y4);
    
    
    set<pii> st2 = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};

    Point a1 = p1.subtract(p2);
    Point a2 = p2.subtract(p3);
    Point b1 = p21.subtract(p22);
    Point b2 = p22.subtract(p23);
    Point c1 = p1.add(p3);
    Point c2 = p21.add(p23);

    Point d = c1.subtract(c2);
    Point u = p1.subtract(p2);

    auto check = [&]() {
        return d.dot(u) >= a1.dot(u) + a2.dot(u) + b1.dot(u) + b2.dot(u);
    };
    int ret = check();
    u = p2.subtract(p3);
    ret |= check();
    u = p21.subtract(p22);
    ret |= check();
    u = p22.subtract(p23);
    ret |= check();
    cout << !ret << endl;
}

int main() {
    _main(0);
    return 0;
}

//2028KB	0ms