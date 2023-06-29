#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t H, W;
    cin >> H >> W;

    char c[H+1][W+1];
    int64_t tab[H+1][W+1];
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> c[i][j];
            tab[i][j] = 0;
        }
        c[i][W] = '#';
    }

    rep(j, 0, W){
        c[H][j] = '#';
    }

    tab[0][0] = 1;
    rep(i, 0, H){
        rep(j, 0, W){
            if(c[i][j] == '#'){
                continue;
            }

            if(c[i][j+1] != '#'){
                tab[i][j+1] += tab[i][j];
            }
            if(c[i+1][j] != '#'){
                tab[i+1][j] += tab[i][j];
            }
        }
    }

    cout << tab[H-1][W-1] << endl;
}