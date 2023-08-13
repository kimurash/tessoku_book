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
    cin >> N;

    cout << N << endl;

    rep(v, 1, N - 1){
        printf("%d %d\n", v, v + 1);
        
    }
    printf("%d 1\n", N);

    return(0);
}