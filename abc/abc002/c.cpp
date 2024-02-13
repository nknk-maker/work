#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
    pair<double, double> p1, p2, p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    double dist1 = dist(p1.first, p1.second, p2.first, p2.second);
    double dist2 = dist(p2.first, p2.second, p3.first, p3.second);
    double dist3 = dist(p3.first, p3.second, p1.first, p1.second);
    printf("%.12lf\n", heron(dist1, dist2, dist3));
    return 0;
}