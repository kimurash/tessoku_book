// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N, K;
    cin >> N >> K;

    int16_t A[N], B[N];
    rep(i, 0, N){
        cin >> A[i] >> B[i];
    }

    int16_t max_cnt = 0;
    for(int a = 1; a <= 100 - K; a++){
        for(int b = 0; b <= 100 - K; b++){
            int16_t cnt = 0;
            rep(i, 0, N){
                if(a <= A[i] && A[i] <= a + K &&
                   b <= B[i] && B[i] <= b + K){
                    cnt++;
                }
            }
            max_cnt = max(max_cnt, cnt);
        }
    }

    cout << max_cnt << endl;
    return(0);
}