#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    int32_t A[N], B[N], C[N], D[N];
    rep(i, 0, N){ cin >> A[i]; }
    rep(i, 0, N){ cin >> B[i]; }
    rep(i, 0, N){ cin >> C[i]; }
    rep(i, 0, N){ cin >> D[i]; }

    int64_t P[N * N], Q[N * N];
    rep(i, 0, N){
        rep(j, 0, N){
            P[i * N + j] = A[i] + B[j];
            Q[i * N + j] = C[i] + D[j];
        }
    }

    sort(Q, Q + N * N);

    rep(i, 0, N * N){
        int64_t r = K - P[i];
        if(binary_search(Q, Q + N * N, r)){
            cout << "Yes" << endl;
            return(0);
        }
    }

    cout << "No" << endl;
}
