// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, W, L, R;
    cin >> N >> W >> L >> R;

    i32 scaffold[N + 2];
    scaffold[0] = 0;
    rep(i, 1, N){
        cin >> scaffold[i];
    }
    scaffold[N + 1] = W;

    mint table[N + 2], acc[N + 2];
    table[0] = acc[0] = 1;
    rep(i, 1, N + 1){
        table[i] = acc[i] = 0;
    }

    rep(i, 1, N + 1){
        i32 left = lower_bound(
            scaffold,
            scaffold + N + 2,
            scaffold[i] - R) - scaffold;

        i32 right = upper_bound(
            scaffold,
            scaffold + N + 2,
            scaffold[i] - L) - scaffold; // <= i

        if(right <= 0){
            table[i] = 0;
        } else{
            if(left <= 0){
                table[i] = acc[right - 1];
            } else{
                table[i] = acc[right - 1] - acc[left - 1];
            }
        }

        acc[i] = acc[i - 1] + table[i];
    }

    cout << table[N + 1].val() << endl;
    return(0);
}