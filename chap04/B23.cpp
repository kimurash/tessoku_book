#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

// ユークリッド距離を求める関数
double calc_euclid_dist(int16_t x1, int16_t y1, int16_t x2, int16_t y2){
    return(sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)));
}

int main(){
    int16_t N;
    cin >> N;

    int16_t X[N], Y[N];
    rep(i, 0, N){
        cin >> X[i] >> Y[i];
    }

    double tab[1 << N][N];
    rep(i, 0, 1 << N){
        rep(j, 0, N){
            tab[i][j] = 1e9;
        }
    }
    tab[0][0] = 0;

    rep(i, 0, 1 << N){
        rep(j, 0, N){
            // 不可能な状態
            if(tab[i][j] == 1e9){
                continue;
            }

            // 既に訪問済みであればスキップ
            rep(k, 0, N){
                if(k == j){ // 都市jは訪問済み
                    continue;
                }
                if((i & (1 << k)) != 0){ // 都市kが訪問済み
                    continue;
                }

                tab[i + (1 << k)][k] = min(
                    tab[i + (1 << k)][k],
                    tab[i][j] + calc_euclid_dist(X[j], Y[j], X[k], Y[k])
                );
            }
        }
    }

    printf("%.5f\n", tab[(1 << N) - 1][0]);
}