#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N, M;
    cin >> N >> M;

    int16_t A[M];
    int16_t include;
    rep(i, 0, M){
        rep(j, 0, N){
            A[i] = 0;
        }
        rep(j, 0, N){
            cin >> include;
            A[i] += include << j;
        }
    }

    int16_t item_max = 1 << N;

    int tab[M+1][item_max];
    rep(i, 0, M + 1){
        rep(j, 0, item_max){
            tab[i][j] = INT16_MAX;
        }
    }
    tab[0][0] = 0;

    rep(i, 0, M){
        rep(j, 0, item_max){
            tab[i+1][j] = min(tab[i][j], tab[i+1][j]);
            tab[i+1][j | A[i]] = min(tab[i+1][j | A[i]], tab[i][j] + 1);
        }
    }

    if(tab[M][item_max - 1] == INT16_MAX){
        cout << -1 << endl;
    } else{
        cout << tab[M][item_max - 1] << endl;
    }
}