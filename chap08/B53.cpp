// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    int16_t D;
    cin >> N >> D;

    int16_t X;
    int32_t Y;
    vector<int32_t> job[D + 1];
    rep(i, 0, N){
        cin >> X >> Y;
        job[X].push_back(Y);
    }

    int32_t sum = 0;
    priority_queue<int32_t> available;
    rep(d, 1, D + 1){
        for(int32_t j: job[d]){
            available.push(j);
        }

        if(!available.empty()){
            sum += available.top();
            available.pop();
        }
    }

    cout << sum << endl;
    return(0);
}