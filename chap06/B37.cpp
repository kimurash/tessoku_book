// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t N;
    cin >> N;

    int64_t ten_pow = 1;
    int64_t R[15][10];
    rep(i, 0, 15){
        // 10のi乗の位の数を取り出す
        int64_t digit = (N % (ten_pow * 10)) / ten_pow;

        rep(j, 0, 10){
            if(j < digit){
                R[i][j] = (N / (ten_pow * 10)) * ten_pow + ten_pow;
            } else if(j == digit){
                R[i][j] = (N / (ten_pow * 10)) * ten_pow + ((N % ten_pow) + 1);
            } else{ // j > digit
                R[i][j] = (N / (ten_pow * 10)) * ten_pow;
            }
        }
        ten_pow *= 10;
    }

    int64_t answer = 0;
    rep(i, 0, 15){
        rep(j, 1, 10){
            answer += j * R[i][j];
        }
    }

    cout << answer << endl;
}