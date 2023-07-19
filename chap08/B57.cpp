// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    int32_t table[30][N + 1];
    rep(j, 0, N + 1){
        int32_t n = j, digit_sum = 0;
        while(n > 0){
            digit_sum += n % 10;
            n /= 10;
        }
        table[0][j] = j - digit_sum;
    }

    rep(i, 1, 30){
        rep(j, 0, N + 1){
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    rep(i, 1, N + 1){
        int32_t answer = i;
        rep(d, 0, 30){
            if(K & (1 << d)){
                answer = table[d][answer];
            }
        }
        cout << answer << endl;
    }

    return(0);
}