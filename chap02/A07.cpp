#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t D, N;
    cin >> D >> N;

    int32_t L, R;
    int32_t dod[D+2] = {0};
    rep(i, 0, N){
        cin >> L >> R;
        dod[L] += 1;
        dod[R+1] -= 1;
    }
    
    int32_t acc[D+1] = {0};
    rep(i, 1, D+1){
        acc[i] = acc[i-1] + dod[i];
        cout << acc[i] << endl;
    }
}