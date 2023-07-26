// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t superior[N + 1];
    rep(i, 2, N){
        cin >> superior[i];
    }

    int32_t subordinate[N + 1] = {0};
    for(int i = N; i >= 2; i--){
        subordinate[superior[i]] += subordinate[i] + 1;
    }

    cout << subordinate[1];
    rep(i, 2, N){
        printf(" %d", subordinate[i]);
    }
    cout << endl;

    return(0);
}