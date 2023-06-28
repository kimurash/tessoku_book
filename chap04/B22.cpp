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

    int32_t travel[N];
    rep(i, 1, N){ travel[i] = INT32_MAX; }
    travel[0] = 0;

    rep(i, 0, N - 2){
        travel[i+1] = min(travel[i+1], travel[i] + A[i+1]);
        travel[i+2] = min(travel[i+2], travel[i] + B[i+2]);
    }
    travel[N-1] = min(travel[N-1], travel[N-2] + A[N-1]);

    cout << travel[N-1] << endl;
}