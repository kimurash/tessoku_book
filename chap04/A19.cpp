#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define IMPOSSIBLE -1

using namespace std;

int main(){
    int16_t N;
    int32_t W;
    cin >> N >> W;

    int32_t weight[N+1], value[N+1];
    rep(i, 1, N + 1){
        cin >> weight[i] >> value[i];
    }

    int64_t tab[N+1][W+1];
    tab[0][0] = 0;
    rep(j, 1, W + 1){
        // wi <= W　=> tab[N][wi] >= wi
        tab[0][j] = IMPOSSIBLE;
    }

    rep(i, 1, N + 1){
        rep(j, 0, W + 1){
            if(j < weight[i]){
                tab[i][j] = tab[i-1][j];
            } else{
                tab[i][j] = max(
                    tab[i-1][j],
                    tab[i-1][j - weight[i]] + value[i]);
            }
        }
    }

    int64_t maxv = 0;
    rep(j, 0, W + 1){
        maxv = max(maxv, tab[N][j]);
    }

    cout << maxv << endl;
}