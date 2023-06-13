#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define XYMAX 1500

using namespace std;

int main(){
    int N;
    cin >> N;

    int grid[XYMAX+1][XYMAX+1];
    rep(i, 0, XYMAX+1){
        rep(j, 0, XYMAX+1){
            grid[i][j] = 0;
        }
    }

    int X, Y;
    rep(i, 0, N){
        cin >> X >> Y;
        grid[X][Y] += 1;
    }

    // 横方向の累積和
    rep(i, 1, XYMAX+1){
        rep(j, 2, XYMAX+1){
            grid[i][j] += grid[i][j-1];
        }
    }

    // 縦方向の累積和
    rep(i, 2, XYMAX+1){
        rep(j, 1, XYMAX+1){
            grid[i][j] += grid[i-1][j];
        }
    }

    int Q;
    cin >> Q;

    int a, b, c, d;
    rep(i, 0, Q){
        cin >> a >> b >> c >> d;
        cout << grid[c][d] + grid[a-1][b-1] - grid[a-1][d] - grid[c][b-1] << endl;
    }
}