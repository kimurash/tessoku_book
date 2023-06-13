#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int H, W, N;
    cin >> H >> W >> N;

    int Z[H+1][W+1];
    rep(i, 0, H+1){
        rep(j, 0, W+1){
            Z[i][j] = 0;
        }
    }

    int A, B, C, D;
    rep(i, 0, N){
        cin >> A >> B >> C >> D;
        Z[A-1][B-1] += 1;
        Z[A-1][D] -= 1;
        Z[C][B-1] -= 1;
        Z[C][D] += 1;
    }

    // 縦方向の累積和
    rep(i, 0, H+1){
        rep(j, 1, W+1){
            Z[i][j] += Z[i][j-1];
        }
    }

    // 横方向の累積和
    rep(i, 1, H+1){
        rep(j, 0, W+1){
            Z[i][j] += Z[i-1][j];
        }
    }

    rep(i, 0, H){
        cout << Z[i][0];
        rep(j, 1, W){
            cout << " " << Z[i][j];
        }
        cout << endl;
    }
}