#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int P[159];

// 0 以上 1 以下のランダムな実数を返す関数
double Randouble() {
    return 1.0 * rand() / RAND_MAX;
}

// a 以上 b 以下の整数をランダムに返す関数
int RandInt(int a, int b) {
    return a + rand() %  (b - a + 1);
}

// 都市 p と 都市 q の間の距離を求める関数
double GetDistance(int p, int q) {
    return sqrt((X[p]-X[q])*(X[p]-X[q]) + (Y[p]-Y[q])*(Y[p]-Y[q]));
}

// スコアを計算する関数
double GetScore() {
    double sum = 0;
    for (int i = 1; i <= N; i++) sum += GetDistance(P[i], P[i+1]);
    return sum;
}

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

    // 初機械生成
    P[1] = 1; P[N + 1] = 1;
    for (int i = 2; i <= N; i++) P[i] = i;

    // 焼きなまし法
    double CurrentScore = GetScore();
    for (int t = 1; t <= 200000; t++) {
        int L = RandInt(2, N);
        int R = RandInt(2, N);
        reverse(P + L, P + R + 1);
        double NewScore = GetScore();

        // 2-opt から唯一変更した部分
        double T = 30.00 - 28.00 * t / 200000.0;
        double Probability = exp(min(0.0, (CurrentScore - NewScore) / T));
        if (Randouble() < Probability) CurrentScore = NewScore;
        else reverse(P + L, P + R + 1);
    }

    // 出力
    for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
    return 0;
}