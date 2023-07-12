// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, L;
    cin >> N >> L;

    char B;
    int32_t A, max_time = 0;
    rep(i, 0, N){
        cin >> A >> B;
        max_time = max(max_time, B == 'E' ? L - A : A);
    }

    cout << max_time << endl;
    return(0);
}