// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    double border = 1.0; // 獲得議席数がK以上になる最大のボーダー
    double left = 1.0, mid, right = 1e9 + 1;
    while(right - left > 1e-6){
        mid = (left + right) / 2.0;

        i32 cnt = 0;
        rep(i, 0, N - 1){
            cnt += (i32)(A[i] / mid);;
        }

        if(cnt < K){
            right = mid;
        } else{
            left = mid;
            border = max(border, mid); // leftが小さくなる可能性もある
        }
    }

    printf("%d", (i32)(A[0] / border));
    rep(i, 1, N - 1){
        printf(" %d", (i32)(A[i] / border));
    }
    putchar('\n');

    return(0);
}