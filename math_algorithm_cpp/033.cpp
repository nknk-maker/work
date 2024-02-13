#include <bits/stdc++.h>
using namespace std;
struct vec{
    long long x;
    long long y;
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
    vec a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    vec AB = makevec(a, b);
    vec AC = makevec(a, c);
    vec BA = makevec(b, a);
    vec BC = makevec(b, c);
    vec CA = makevec(c, a);
    vec CB = makevec(c, b);

    int pattern = 3;
    if (dot(BA, BC) < 0) pattern = 1;
    if (dot(CA, CB) < 0) pattern = 2;

    double ans;
    if (pattern == 1) {
        ans = vecabs(AB);
    }
    if (pattern == 2) {
        ans = vecabs(AC);
    }
    if (pattern == 3) {
        long long S = abs(cross(BA, BC));
        double x = vecabs(BC);
        ans = 1.0 * S / x;
    }

    printf("%.12lf\n", ans);
}