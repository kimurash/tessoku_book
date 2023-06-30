// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 1000000007

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int64_t a1 = 1, a2 = 1;
    for(int i = 3; i <= N; i++){
        int64_t a3 = (a1 + a2) % MOD;
        a1 = a2;
        a2 = a3;
    }

    cout << a2 << endl;
}