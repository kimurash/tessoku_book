#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int tab[1009][1009]; // maxの引数の型を一致させるためint型で宣言

int main(){
    int16_t N;
    string S;
    cin >> N >> S;

    rep(i, 1, N + 1){
        tab[i][i] = 1;
    }

    rep(i, 1, N){
        tab[i][i+1] = S.at(i-1) == S.at(i) ? 2 : 1;
    }

    for(int d = 2; d <= N - 1; d++){
        for(int l = 1; l + d <= N; l++){
            int r = l + d;

            tab[l][r] = max(tab[l+1][r], tab[l][r-1]);
            if(S.at(r-1) == S.at(l-1)){
                tab[l][r] = max(tab[l][r], tab[l+1][r-1] + 2);
            }
        }
    }

    cout << tab[1][N] << endl;
}