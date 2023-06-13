#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N] = {0};
    rep(i, 0, N){ cin >> A[i]; }

    int fmax[N] = {0}, bmax[N] = {0};
    fmax[0] = A[0];     // 前方からの最大値
    bmax[N-1] = A[N-1]; // 後方からの最大値
    rep(i, 1, N){
        fmax[i] = max(fmax[i-1], A[i]);
        bmax[N - i -1] = max(bmax[N-i], A[N - i - 1]);
    }

    int D;
    cin >> D;

    int L, R, maxcap;
    rep(i, 0, D){
        cin >> L >> R;
        cout << max(fmax[L-2], bmax[R]) << endl;
    }
}