#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    int32_t A[N] = {0}, acc[N+1] = {0};
    rep(i, 0, N){
        cin >> A[i];
        acc[i+1] = acc[i] + A[i];
    }

    int32_t L, R;
    rep(i, 0, Q){
        cin >> L >> R;
        cout << acc[R] - acc[L-1] << endl;
    }
}