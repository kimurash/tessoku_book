// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 1000000007

using namespace std;

int main(){
    int32_t n, r;
    cin >> n >> r;

    int64_t num = 1; // 分子
    for(int i = r + 1; i <= n; i++){
        num = (num * i) % MOD;
    }

    int64_t den = 1; // 分母
    for(int i = 2; i <= n - r; i++){
        den = (den * i) % MOD;
    }

    int64_t den_pow = 1;
    int64_t power = den;
    for(int i = 0; i <= 30; i++){
        if((MOD - 2) & (1 << i)){
            den_pow = (den_pow * power) % MOD;
        }
        power = (power * power) % MOD;
    }

    cout << (num * den_pow) % MOD << endl;
}