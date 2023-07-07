// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, M, B;
    cin >> N >> M >> B;

    int16_t travel;
    int64_t sum_A = 0;
    rep(i, 0, N){
        cin >> travel;
        sum_A += travel;
    }

    int64_t sum_C = 0;
    rep(i, 0, M){
        cin >> travel;
        sum_C += travel;
    }

    cout << sum_A * M + 1LL * B * N * M + sum_C * N << endl;
}