// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<double, int32_t> pdi32;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    double A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 divisor[N + 1]; // 各政党の割る数
    rep(i, 1, N){
        divisor[i] = 1;
    }

    priority_queue<pdi32, vector<pdi32>> pq;
    rep(i, 1, N){
        pq.push(make_pair(A[i], i));
    }

    i32 answer[N + 1] = {0};
    rep(i, 1, K){
        pdi32 top = pq.top(); pq.pop();
        i32 party = top.second;

        answer[party]++;

        divisor[party]++;
        pq.push(make_pair(A[party] / (divisor[party]), party));
    }

    cout << answer[1];
    rep(i, 2, N){
        printf(" %d", answer[i]);
    }
    cout << endl;

    return(0);
}