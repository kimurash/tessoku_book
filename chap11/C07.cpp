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

    i32 price[N];
    rep(n, 0, N - 1){
        cin >> price[n];
    }

    sort(price, price + N);

    i32 acc[N];
    acc[0] = price[0];
    rep(n, 1, N - 1){
        acc[n] = acc[n - 1] + price[n];
    }

    i32 Q;
    cin >> Q;

    i32 X;
    rep(q, 1, Q){
        cin >> X;
        i32 ans = upper_bound(acc, acc + N, X) - acc;
        cout << ans << endl;
    }

    return(0);
}