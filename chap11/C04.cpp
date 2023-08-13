// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    vector<i64> divisor;
    rep(n, 1, sqrt(N)){
        if(N % n == 0){
            divisor.push_back(n);
            divisor.push_back(N / n);
        }
    }

    sort(all(divisor));

    for(i64 d : divisor){
        cout << d << endl;
    }

    return(0);
}