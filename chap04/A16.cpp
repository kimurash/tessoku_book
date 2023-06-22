#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N], B[N] = {0};
    rep(i, 1, N){ cin >> A[i]; }
    rep(i, 2, N){ cin >> B[i]; }

    int32_t travel[N] = {0};
    travel[1] = A[1];
    rep(i, 2, N){
        travel[i] = min(
            travel[i-1] + A[i],
            travel[i-2] + B[i]
        );
    }

    cout << travel[N-1] << endl;
}