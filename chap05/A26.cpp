#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAXN 300000

using namespace std;

int main(){
    bool prime[MAXN+1];
    rep(i, 2, MAXN + 1){
        prime[i] = true;
    }

    for(int i = 2; i * i < MAXN; i++){
        if(!prime[i]){
            continue;
        }
        for(int j = 2 * i; j <= MAXN; j += i){
            prime[j] = false;
        }
    }

    int32_t Q, X;
    cin >> Q;

    rep(i, 0, Q){
        cin >> X;
        if(prime[X]){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
}