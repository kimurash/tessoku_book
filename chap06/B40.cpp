// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 100

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A;
    int64_t R[MOD] = {0};
    rep(i, 0, N){
        cin >> A;
        R[A % MOD]++;
    }

    int64_t sum = 0;
    int32_t half = MOD / 2;
    if(R[0] >= 2){
        sum += R[0] * (R[0] - 1) / 2;
    }
    for(int i = 1; i <= half - 1; i++){
        sum += R[i] * R[MOD - i];
    }
    if(R[half] >= 2){
        sum += R[half] * (R[half] - 1) / 2;
    }

    cout << sum << endl;
}