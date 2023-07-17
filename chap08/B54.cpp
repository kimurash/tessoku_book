// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A;
    int64_t answer = 0;
    map<int32_t, int32_t> cntmap;
    rep(i, 0, N){
        cin >> A;
        answer += cntmap[A]; // mapの初期値は0
        cntmap[A]++;
    }

    cout << answer << endl;
    return(0);
}