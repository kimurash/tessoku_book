// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 1000000007

using namespace std;

int main(){
    int32_t H, W;
    cin >> H >> W;

    int64_t num = 1, den = 1;
    for(int i = 2; i <= H + W - 2; i++){
        num = (num * i) % MOD;
    }

    for(int i = 2; i <= H - 1; i++){
        den = (den * i) % MOD;
    }

    for(int i = 2; i <= W - 1; i++){
        den = (den * i) % MOD;
    }

    int64_t den_pow = 1;
    int64_t power = den;
    for(int i = 0; i <= 30; i++){
        if(MOD - 2 & (1 << i)){
            den_pow = (den_pow * power) % MOD;
        }
        power = (power * power) % MOD;
    }

    cout << (num * den_pow) % MOD << endl;
}