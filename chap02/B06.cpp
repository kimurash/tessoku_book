#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A, acc[N+1] = {0};
    rep(i, 0, N){
        cin >> A;
        acc[i+1] += A + acc[i];
    }

    int32_t Q, L, R;
    int32_t winning;
    cin >> Q;
    rep(i, 0, Q){
        cin >> L >> R;
        winning = 2 * (acc[R] - acc[L-1]);
        if(winning > R - L + 1){
            cout << "win" << endl;
        } else if(winning < R - L + 1){
            cout << "lose" << endl;
        } else{
            cout << "draw" << endl;
        }
    }
}