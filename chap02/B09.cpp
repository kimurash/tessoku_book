#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define XYMAX 1500

using namespace std;

int main(){
    int N;
    cin >> N;

    int grid[XYMAX+9][XYMAX+9];
    rep(i, 0, XYMAX+1){
        rep(j, 0, XYMAX+1){
            grid[i][j] = 0;
        }
    }

    int A, B, C, D;
    rep(i, 0, N){
        cin >> A >> B >> C >> D;
        grid[A][B] += 1;
        grid[C][B] -= 1;
        grid[A][D] -= 1;
        grid[C][D] += 1;
    }

    // 横方向の累積和
    rep(i, 0, XYMAX+1){
        rep(j, 1, XYMAX+1){
            grid[i][j] += grid[i][j-1];
        }
    }

    // 縦方向の累積和
    rep(i, 1, XYMAX+1){
        rep(j, 0, XYMAX+1){
            grid[i][j] += grid[i-1][j];
        }
    }

    // 面積を求める
    int area = 0;
    rep(i, 0, XYMAX){
        rep(j, 0, XYMAX){
            if(grid[i][j] > 0){
                area += 1;
            }
        }
    }

    cout << area << endl;
}