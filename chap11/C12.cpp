// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 300
#define MAXM 59

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

i16 N, M;

pi16 edge[MAXM];
i16 score[MAXN][MAXN];

void calc_score();

int main(){
    cin.tie(nullptr);

    i16 K;
    cin >> N >> M >> K;

    i16 A, B;
    rep(i, 1, M){
        cin >> A >> B;
        edge[i] = make_pair(A, B);
    }

    calc_score();

    // table[i][j]: i章目までにjページまでを割り当てたときの小説の良さの最大値
    // intでないとmaxできない
    int table[K + 1][N + 1];

    rep(i, 1, K){
        // 0ページまでを割り当てることはできない
        // 解答に影響しない値で初期化
        table[i][0] = INT_MIN;
    }

    rep(j, 1, N){
        table[1][j] = score[1][j];
    }

    rep(i, 2, K){ // i章まで
        rep(j, 1, N){ // jページまで
            table[i][j] = INT_MIN;
            rep(k, 1, j){ // k ~ jページをi章に割り当てる
                table[i][j] = max(
                    table[i][j],
                    table[i - 1][k - 1] + score[k][j]);
            }
        }
    }

    cout << table[K][N] << endl;
    return(0);
}

void calc_score(){
    rep(i, 1, N){
        rep(j, i, N){
            score[i][j] = 0;
            rep(k, 1, M){
                if(i <= edge[k].first && edge[k].second <= j){
                    score[i][j]++;
                }
            }
        }
    }
}