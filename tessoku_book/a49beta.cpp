#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct State {
    int score; // 配列Xの絶対値の合計
    int X[29]; // 現在の配列 X の値
    char Lastmove; // 最後の動き（'A' または 'B')
    int Lastpos; // Beam[i-1][どこ]から遷移したか
};

// sort 関数の順序を決める（スコアが大きいほうが「大きい」とする）
bool operator>(const State& a1, const State& a2) {
    if (a1.score < a2.score) return true;
    else return false;
}

// 必要な変数・配列（WIDHはビーム幅、 NumState[i]は i 手目時点での状態数）
const int WIDTH = 10000;
const int N = 20;
int T, P[109], Q[109], R[109];
int NumState[109];
State Beam[109][WIDTH];
char Answer[109];

// ビームサーチを行う関数
void BeamSearch() {
// 0手目の状態を設定
// NumState[i] は i 手目時点での状態数（必ずビーム幅以下になる）
// 0手目は X = [0, 0, 0,... 0]　しか存在しないので、NumState[0] = 1
NumState[0] = 1;
Beam[0][0].score = 0;
for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

// ビームサーチ
for (int i = 1; i <= T; i++) {
    vector<State> Candidate;
    for (int j = 0; j < NumState[i-1]; j++) {
        // 操作 A の場合
        State SousaA = Beam[i-1][j];
        SousaA.Lastmove = 'A';
        SousaA.Lastpos = j;
        SousaA.X[P[i]] += 1;
        SousaA.X[Q[i]] += 1;
        SousaA.X[R[i]] += 1;
        for (int k = 1; k <= N; k++) {
            SousaA.score += abs(SousaA.X[k]);
        }

        // 操作 B の場合
        State SousaB = Beam[i-1][j];
        SousaB.Lastmove = 'B';
        SousaB.Lastpos = j;
        SousaB.X[P[i]] -= 1;
        SousaB.X[Q[i]] -= 1;
        SousaB.X[R[i]] -= 1;
        for (int k = 1; k <= N; k++) {
            SousaB.score += abs(SousaB.X[k]);
        }

        // 候補に追加
        Candidate.push_back(SousaA);
        Candidate.push_back(SousaB);
    }

    // ソートしてBeam[i] の結果を計算する
    sort(Candidate.begin(), Candidate.end(), greater<State>());
    NumState[i] = min(WIDTH, (int)Candidate.size());
    for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];
}
}

int main() {
    // 入力
    cin >> T;
    for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];
    
    // ビームサーチ
    BeamSearch();

    // 操作手順の復元
    int CurrentPlace = 0;
    for (int i = T; i >= 1; i--) {
        Answer[i] = Beam[i][CurrentPlace].Lastmove;
        CurrentPlace = Beam[i][CurrentPlace].Lastpos;
    }

    // 出力
    for (int i = 1; i <= T; i++) cout << Answer[i] << endl;
    return 0;
}

