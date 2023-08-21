// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, P;
    cin >> N >> P;

    i64 B;
    mint A[N + 1];
    rep(i, 1, N){
        cin >> B;
        A[i] = B;
    }

    i64 answer = 0;
    map<i32, i32> cnt;
    rep(i, 1, N){
        if(A[i] == 0){
            if(P == 0){
                answer += i - 1;
            }
        } else{
            mint inv = P * A[i].inv();
            answer += cnt[inv.val()];
        }
        cnt[A[i].val()]++;
    }
    
    cout << answer << endl;
    return(0);
}