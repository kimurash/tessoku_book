#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

#define UNREACHABLE -150 * 100000 * 10

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N], B[N];
    rep(i, 1, N){ cin >> A[i]; }
    rep(i, 1, N){ cin >> B[i]; }

    int tab[N + 1]; // maxの引数の型を一致させるためint型で宣言
    tab[1] = 0;
    rep(i, 2, N + 1){
        tab[i] = UNREACHABLE;
    }

    rep(i, 1, N){
        tab[A[i]] = max(tab[A[i]], tab[i] + 100);
        tab[B[i]] = max(tab[B[i]], tab[i] + 150);
    }

    cout << tab[N] << endl;
}