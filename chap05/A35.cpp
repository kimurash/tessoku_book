// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    cin >> N;

    int32_t A[N];
    rep(i, 0, N){
        cin >> A[i];
    }

    int32_t pyramid[N][N];
    rep(j, 0, N){
        pyramid[N - 1][j] = A[j];
    }

    for(int i = N - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(i & 1){ // iが奇数
                pyramid[i][j] = min(pyramid[i+1][j], pyramid[i+1][j+1]);
            } else{ // iが偶数
                pyramid[i][j] = max(pyramid[i+1][j], pyramid[i+1][j+1]);
            }
        }
    }

    cout << pyramid[0][0] << endl;
}