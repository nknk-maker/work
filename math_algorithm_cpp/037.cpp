#include <bits/stdc++.h>
using namespace std;
struct vec{
    long long x;
    long long y;
};
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

vec a, b, c, d;

int main() {
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    // 位置ベクトルからベクトルを作成
    vec BA, BC, BD, DA, DB, DC;
    BA = makevec(b, a);
    BC = makevec(b, c);
    BD = makevec(b, d);
    DA = makevec(d, a);
    DB = makevec(d, b);
    DC = makevec(d, c);

    bool flag1 = false, flag2 = false;
    long long c1, c2, c3, c4;
    c1 = cross(BA, BC);
    c2 = cross(BA, BD);
    c3 = cross(DC, DA);
    c4 = cross(DC, DB);


    // コーナーケース
    if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) {
        // A, B, C, Dをpairとして管理
        // 適切にswapする
        // 区間が重なるかの判定
        pair<long long, long long> A = make_pair(a.x, a.y);
        pair<long long, long long> B = make_pair(b.x, b.y);
        pair<long long, long long> C = make_pair(c.x, c.y);
        pair<long long, long long> D = make_pair(d.x, d.y);
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        if (max(A, C) <= min(B, D)) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    if (c1 <= 0 && c2 >= 0) flag1 = true;
    if (c1 >= 0 && c2 <= 0) flag1 = true;
    if (c3 <= 0 && c4 >= 0) flag2 = true;
    if (c3 >= 0 && c4 <= 0) flag2 = true;


    if (flag1 && flag2) cout << "Yes" << endl;
    else cout << "No" << endl;
}