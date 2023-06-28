#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N+1];
    int32_t tab[N+1], L[N+1];
    rep(i, 1, N + 1){
        cin >> A[i];
        L[i] = INT32_MAX;
    }

    int range = 0;
    rep(i, 1, N + 1){
        // A[i]以上の最小の要素
        int idx = lower_bound(L + 1, L + 1 + range, A[i]) - L;

        tab[i] = idx;
        L[idx] = A[i];
        if(idx > range){
            range++;
        }
    }

    cout << range << endl;
}