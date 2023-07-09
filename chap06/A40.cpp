// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAXLEN 100

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int16_t A;
    int32_t len_cnt[MAXLEN + 1] = {0};
    rep(i, 0, N){
        cin >> A;
        len_cnt[A]++;
    }

    int64_t sum = 0;
    rep(i, 1, MAXLEN + 1){
        if(len_cnt[i] >= 3){
            sum += 1LL * len_cnt[i] * (len_cnt[i] - 1) * (len_cnt[i] - 2) / 6;
        }
    }

    cout << sum << endl;
}