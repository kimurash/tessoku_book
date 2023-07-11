// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    char S[N];
    rep(i, 0, N){
        cin >> S[i];
    }

    int32_t cnt = 1;
    char crrnt_color = S[0];
    rep(i, 1, N){
        if(S[i] == crrnt_color){
            cnt++;
            if(cnt >= 3){
                cout << "Yes" << endl;
                return(0);
            }
        } else{
            crrnt_color = S[i];
            cnt = 1;
        }
    }

    cout << "No" << endl;
    return(0);
}