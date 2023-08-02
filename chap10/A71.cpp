// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 A[N], B[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }
    rep(i, 0, N - 1){
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, greater<i16>());

    i32 effort = 0;
    rep(i, 0, N - 1){
        effort += A[i] * B[i];
    }

    cout << effort << endl;
    return(0);
}