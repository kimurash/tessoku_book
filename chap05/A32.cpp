// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, A, B;
    cin >> N >> A >> B;

    bool win[N + 1]; // 先手の勝敗
    rep(i, 0, N + 1){
        // 次状態に負けがある => 先手は勝ち
        // 次状態が勝ちしかない => 先手は負け
        if(i < A){
            win[i] = false;
        } else if(i < B){
            if(win[i - A]){
                win[i] = false;
            } else{
                win[i] = true;
            }
        } else{
            if(win[i - A] && win[i - B]){
                win[i] = false;
            } else{
                win[i] = true;
            }
        }
    }

    if(win[N]){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
}