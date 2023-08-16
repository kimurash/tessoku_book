// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i64 table[N + 1];
    table[1] = A[1];
    table[2] = A[2];
    rep(d, 3, N){
        table[d] = max(
            table[d - 2] + A[d],
            table[d - 1]
        );
    }

    cout << table[N] << endl;
    return(0);
}