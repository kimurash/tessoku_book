#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    bool prime[N+1];
    rep(i, 2, N + 1){
        prime[i] = true;
    }

    for(int i = 2; i * i < N; i++){
        if(!prime[i]){
            continue;
        }
        for(int j = 2 * i; j <= N; j += i){
            prime[j] = false;
        }
    }

    rep(i, 2, N + 1){
        if(prime[i]){
            cout << i << endl;
        }
    }
}