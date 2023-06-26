#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    int32_t tab[S.length()+1][T.length()+1];

    rep(j, 0, T.length() + 1){
        tab[0][j] = 0;
    }

    rep(i, 1, S.length() + 1){
        rep(j, 0, T.length() + 1){
            if(j == 0){
                tab[i][j] = tab[i-1][j];
            } else{
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
                if(S.at(i - 1) == T.at(j - 1)){
                    tab[i][j] = max(tab[i][j], tab[i-1][j-1] + 1);
                }
            }
        }
    }
///*
    rep(i, 0, S.length() + 1){
        rep(j, 0, T.length() + 1){
            printf("%d ", tab[i][j]);
        }
        cout << endl;
    }
//*/
    cout << tab[S.length()][T.length()] << endl;
}