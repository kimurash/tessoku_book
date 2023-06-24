#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    int32_t S;
    cin >> N >> S;

    int32_t A[N+1];
    rep(i, 1, N+1){ cin >> A[i]; }

    bool able[N+1][S+1]; // i番目までのカードを使ってjを作れるか
    able[0][0] = true;
    rep(j, 1, S + 1){ able[0][j] = false; }

    rep(i, 1, N + 1){
        rep(j, 0, S + 1){
            if(j - A[i] < 0){
                able[i][j] = able[i-1][j];
            } else{
                able[i][j] = able[i-1][j] || able[i-1][j - A[i]];
            }
        }
    }

    if(able[N][S]){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}