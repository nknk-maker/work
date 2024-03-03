#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int x2) {
    return max(min(x1, x2) + 7 - max(x1, x2), 0);
}

int dist3(int x1, int x2, int x3) {
    if (x1 > x2) swap(x1, x2);
    if (x1 > x3) swap(x1, x3);
    if (x2 > x3) swap(x2, x3);
    return max(0, x1 + 7 - x3);
}

int vol(int x1, int y1, int z1, int x2, int y2, int z2) {
    return max(dist(x1, x2) * dist(y1, y2) * dist(z1, z2), 0);
}

int main() {
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    for (int ix = -14; ix <= 7; ix++) {
        for (int iy = -7; iy <= 7; iy++) {
            for (int iz = -7; iz <= 7; iz++) {
                for (int jx = -14; jx <= 14; jx++) {
                    for (int jy = -14; jy <= 14; jy++) {
                        for (int jz = -14; jz <= 14; jz++) {
                            int vol2 = vol(0, 0, 0, ix, iy, iz) + vol(0, 0, 0, jx, jy, jz) + vol(ix, iy, iz, jx, jy, jz);
                            int vol3 = dist3(0, ix, jx) * dist3(0, iy, jy) * dist3(0, iz, jz);
                            vol2 -= vol3 * 3;
                            int vol1 = 1029 - vol2 * 2 - vol3 * 3;
                            if ((vol1 == v1 && vol2 == v2) && vol3 == v3) {
                                cout << "Yes" << endl;
                                cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << ix << ' ' << iy << ' ' << iz << ' ' << jx << ' ' << jy << ' ' << jz << ' ' << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}