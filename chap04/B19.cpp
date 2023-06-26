#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_VALUE 100000 //= 100 x 1000

using namespace std;

int main(){
    int16_t N;
    int32_t W;
    cin >> N >> W;

    int32_t weight[N+1], value[N+1];
    rep(i, 1, N + 1){
        cin >> weight[i] >> value[i];
    }

    int64_t tab[N+1][MAX_VALUE+1];
    tab[0][0] = 0;
    rep(j, 1, MAX_VALUE + 1){
        tab[0][j] = INT32_MAX;
    }

    rep(i, 1, N + 1){
        rep(j, 0, MAX_VALUE + 1){
            if(j < value[i]){
                tab[i][j] = tab[i-1][j];
            } else{
                tab[i][j] = min(
                    tab[i-1][j],
                    tab[i-1][j - value[i]] + weight[i]);
            }
        }
    }

    int32_t maxv = 0;
    rep(j, 0, MAX_VALUE + 1){
        if(tab[N][j] <= W && maxv < j){
            maxv = j;
        }
    }

    // cout << maxv << endl;
    cout << maxv << endl;
}