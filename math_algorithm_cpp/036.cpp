#include <bits/stdc++.h>
using namespace std;
struct vec{
    double x;
    double y;
};
vec a, b, c;
long long dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}
long long cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
double vecabs(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
vec makevec(vec a, vec b) {
    vec ab;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    return ab;
}
int main() {
    long long A, B, H, M;
    cin >> A >> B >> H >> M;
    double h_pi = 1.0 * H / 6 * M_PI + 1.0 * M / 360 * M_PI;
    double m_pi = 1.0 * M / 30 * M_PI;
    vec a, b;
    a.x = A * cos(h_pi);
    a.y = A * sin(h_pi);
    b.x = B * cos(m_pi);
    b.y = B * sin(m_pi);
    vec ab = makevec(a, b);
    double ans = vecabs(ab);
    printf("%.12lf\n", ans);
}
