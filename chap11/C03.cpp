// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 D;
    cin >> D;

    i32 diff;
    i32 price[D + 1];
    cin >> price[1];
    rep(d, 2, D){
        cin >> diff;
        price[d] = price[d - 1] + diff;
    }

    i32 Q;
    i32 S, T;
    cin >> Q;
    rep(q, 1, Q){
        cin >> S >> T;
        if(price[S] == price[T]){
            cout << "Same" << endl;
        } else{
            cout << (price[S] > price[T] ? S : T) << endl;
        }
    }

    return(0);
}