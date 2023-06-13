#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    int X[H+1][W+1];
    rep(i, 0, H+1){
        rep(j, 0, W+1){
            if(i == 0 || j == 0){
                X[i][j] = 0;
            } else if(j == 1){
                cin >> X[i][j];
            } else {
                cin >> X[i][j];
                X[i][j] += X[i][j-1]; // 横方向の累積和
            }
        }
    }

    rep(j, 1, W+1){
        rep(i, 2, H+1){
            X[i][j] += X[i-1][j]; // 縦方向の累積和
        }
    }

    int Q;
    cin >> Q;

    int A, B, C, D;
    rep(i, 0, Q){
        cin >> A >> B >> C >> D;
        cout << X[C][D] + X[A-1][B-1] - X[A-1][D] - X[C][B-1] << endl;
    }
}