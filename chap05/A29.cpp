// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 1000'000'007

using namespace std;

int main(){
    int16_t a;
    int32_t b;
    cin >> a >> b;

    int64_t answer = 1;
    int64_t power = a;
    for(int i = 0; i <= 30; i++){
        if(b & (1 << i)){
            answer = (answer * power) % MOD;
        }
        power = (power * power) % MOD;
    }

    cout << answer << endl;
}