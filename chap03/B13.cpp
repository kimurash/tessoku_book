#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    vector<int32_t> A(N+1, 0);
    rep(i, 1, N+1){ cin >> A.at(i); }

    int64_t acc[N+1] = {0};
    rep(i, 1, N+1){
        acc[i] = A[i] + acc[i-1];
    }

    int32_t R[N+1] = {1};
    int64_t count = 0;
    rep(i, 1, N + 1){
        R[i] = R[i-1];
        while(R[i] < N+1 && acc[R[i]] - acc[i-1] <= K){
            R[i]++;
        }

        count += R[i] - i;
    }

    cout << count << endl;
}