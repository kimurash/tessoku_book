#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int32_t tab[2009][2009];

int main(){
    int16_t N;
    cin >> N;

    int16_t P[N+2] = {0}, A[N+2] = {0};
    rep(i, 1, N + 1){
        cin >> P[i] >> A[i];
    }

    tab[1][N] = 0;
    for(int d = N - 2; d >= 0; d--){
        for(int l = 1; l + d <= N; l++){
            int r = l + d;

            int32_t score1 = 0;
            if(l <= P[l-1] && P[l-1] <= r){
                score1 = A[l-1];
            }

            int32_t score2 = 0;
            if(l <= P[r+1] && P[r+1] <= r){
                score2 = A[r+1];
            }

            tab[l][r] = max(
                tab[l-1][r] + score1,
                tab[l][r+1] + score2
            );

            // printf("(%d, %d): %d\n", l, r, tab[l][r]);
        }
    }

    // 対角成分の最大値を求める
    int32_t answer = 0;
    rep(i, 0, N){
        answer = max(answer, tab[i][i]);
    }
    cout << answer << endl;
}