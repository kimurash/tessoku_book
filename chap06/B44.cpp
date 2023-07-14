// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    cin >> N;

    int16_t grid[N][N];
    int16_t row_map[N];
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> grid[i][j];
        }
        row_map[i] = i;
    }

    int32_t Q;
    int16_t qno, x, y;

    cin >> Q;
    rep(i, 0, Q){
        cin >> qno >> x >> y;
        switch (qno){
        case 1: // 交換操作
            swap(row_map[x - 1], row_map[y - 1]);
            break;

        case 2: // 取得操作
            cout << grid[row_map[x - 1]][y - 1] << endl;
            break;
        }
    }

    return(0);
}