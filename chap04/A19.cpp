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

    int64_t worktab[N+1][W+1];
    worktab[0][0] = 0;
    rep(j, 1, W + 1){
        // wi <= W　=> worktab[N][wi] >= wi
        worktab[0][j] = IMPOSSIBLE;
    }

    rep(i, 1, N + 1){
        rep(j, 0, W + 1){
            if(j < weight[i]){
                worktab[i][j] = worktab[i-1][j];
            } else{
                worktab[i][j] = max(
                    worktab[i-1][j],
                    worktab[i-1][j - weight[i]] + value[i]);
            }
        }
    }

    int64_t maxv = 0;
    rep(j, 0, W + 1){
        maxv = max(maxv, worktab[N][j]);
    }

    cout << maxv << endl;
}