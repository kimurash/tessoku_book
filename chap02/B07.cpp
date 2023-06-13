#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t T, N;
    cin >> T >> N;

    int32_t L, R;
    int32_t tot[T+1] = {0};
    rep(i, 0, N){
        cin >> L >> R;
        tot[L] += 1;
        tot[R] -= 1;
    }

    int32_t acc[T+1] = {0};
    acc[0] = tot[0];
    rep(i, 0, T){
        cout << acc[i] << endl;
        acc[i+1] = acc[i] + tot[i+1];
    }
}