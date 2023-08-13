// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N; N--;

    string S = "4444444444";
    rep(d, 0, 9){
        if(N & (1 << d)){
            S[9 - d] = '7';
        }
    }

    cout << S << endl;
    return(0);
}