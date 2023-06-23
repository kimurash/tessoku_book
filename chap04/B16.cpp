#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t h[N];
    rep(i, 0, N){ cin >> h[i]; }

    int32_t sum_cost[N] = {0};
    sum_cost[1] = abs(h[1] - h[0]);
    rep(i, 2, N){
        sum_cost[i] = min(
            sum_cost[i-2] + abs(h[i] - h[i-2]),
            sum_cost[i-1] + abs(h[i] - h[i-1])
        );
    }

    cout << sum_cost[N-1] << endl;
}