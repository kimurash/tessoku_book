// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 100'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 N, L, K;
i32 A[MAXN];

i32 cut_yokan(i32 len){
    i32 cnt = 1;
    i32 left = 0;

    rep(i, 1, N){
        if(L - A[i] < len){
            break;
        }

        if(A[i] - left >= len){
            cnt++;
            left = A[i];
        }
    }

    return(cnt);
}

int main(){
    cin.tie(nullptr);

    cin >> N >> L >> K;
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 low = 1, mid, high = L + 1; // 最短ピースの長さ
    while(low + 1 < high){
        mid = (low + high) / 2;
        i32 cnt = cut_yokan(mid);
        if(cnt < K + 1){
            high = mid;
        } else{
            low = mid;
        }
    }

    cout << low << endl;
    return(0);
}