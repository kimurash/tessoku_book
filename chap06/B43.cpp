// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, M;
    cin >> N >> M;

    int32_t score[N];
    rep(i, 0, N){
        score[i] = M;
    }

    int32_t A;
    rep(i, 0, M){
        cin >> A;
        score[A - 1]--;
    }

    rep(i, 0, N){
        cout << score[i] << endl;
    }

    return(0);
}