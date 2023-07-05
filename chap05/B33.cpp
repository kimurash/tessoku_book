// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, H, W;
    cin >> N >> H >> W;

    int32_t coordinate, nim_sum = 0;
    rep(i, 0, 2 * N){
        cin >> coordinate;
        nim_sum ^= coordinate - 1;
    }

    if(nim_sum == 0){
        cout << "Second" << endl;
    } else{
        cout << "First" << endl;
    }
}