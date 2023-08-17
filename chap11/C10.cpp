// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i64 W;
    cin >> W;

    mint answer = 12;
    mint power = 7;
    for(int i = 0; i <= 60; i++){
        if((W - 1) & (1LL << i)){
            answer = (answer * power);
        }
        power = (power * power);
    }

    cout << answer.val() << endl;
    return(0);
}