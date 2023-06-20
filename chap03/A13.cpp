#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    int32_t A[N] = {0};
    rep(i, 0, N){ cin >> A[i]; }

    int32_t R = 0;
    int64_t count = 0;
    rep(i, 0, N - 1){
        while(R < N && A[R] - A[i] <= K){
            R++;
        }
        count += R - (i + 1);
    }

    cout << count << endl;
}