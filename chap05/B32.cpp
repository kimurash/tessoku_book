// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    int16_t K;
    cin >> N >> K;

    int32_t a[K];
    rep(i, 0, K){
        cin >> a[i];
    }

    bool win[N+1];
    rep(i, 0, N + 1){
        win[i] = false;
        rep(j, 0, K){
            if(i >= a[j] && !win[i - a[j]]){
                win[i] = true;
                break;
            }
        }
    }

    if(win[N]){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
}