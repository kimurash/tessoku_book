// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    int32_t A[N + 1];
    int32_t tab[30][N + 1];
    rep(i, 1, N + 1){
        cin >> A[i];
        tab[0][i] = A[i];
    }

    rep(i, 1, 30){
        rep(j, 1, N + 1){
            tab[i][j] = tab[i - 1][tab[i - 1][j]];
        }
    }

    int32_t X, Y;
    rep(i, 0, Q){
        cin >> X >> Y;
        rep(d, 0, 30){
            if(Y & (1 << d)){
                X = tab[d][X];
            }
        }
        cout << X << endl;
    }
}