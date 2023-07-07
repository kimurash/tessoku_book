// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t D, N;
    cin >> D >> N;

    int16_t L, R, H;
    int16_t limit[D + 1];
    rep(i, 1, D + 1){
        limit[i] = 24;
    }

    rep(i, 0, N){
        cin >> L >> R >> H;
        rep(i, L, R + 1){
            limit[i] = min(limit[i], H);
        }
    }

    int16_t sum = 0;
    rep(i, 1, D + 1){
        sum += limit[i];
    }
    cout << sum << endl;
}