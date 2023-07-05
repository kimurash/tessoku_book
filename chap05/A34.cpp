// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAX_N 100000

using namespace std;

int main(){
    int32_t N, X, Y;
    cin >> N >> X >> Y;

    int32_t A[N];
    rep(i, 0, N){ cin >> A[i]; }

    int32_t grundy[MAX_N + 1];
    rep(i, 0, MAX_N + 1){
        // 操作が2つしかないためgrundy数の最大値は2
        bool transit[3] = {false, false, false};
        if(i >= X){
            transit[grundy[i - X]] = true;
        }
        if(i >= Y){
            transit[grundy[i - Y]] = true;
        }

        if(!transit[0]){
            grundy[i] = 0;
        } else if(!transit[1]){
            grundy[i] = 1;
        } else{
            grundy[i] = 2;
        }
    }

    int32_t result = grundy[A[0]];
    rep(i, 1, N){
        result ^= grundy[A[i]];
    }

    if(result != 0){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
}