#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    int16_t tab[S.length()+1][T.length()+1];
    rep(i, 0, S.length() + 1){
        tab[i][0] = i;
    }
    rep(j, 0, T.length() + 1){
        tab[0][j] = j;
    }

    rep(i, 1, S.length() + 1){
        rep(j, 1, T.length() + 1){
            tab[i][j] = min(
                min(tab[i-1][j] + 1, tab[i][j-1] + 1),
                tab[i-1][j-1] + (S.at(i-1) == T.at(j-1) ? 0 : 1)
            );
        }
    }

    cout << tab[S.length()][T.length()] << endl;
}