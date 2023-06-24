#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t h[N];
    rep(i, 0, N){ cin >> h[i]; }

    int32_t jmp1, jmp2;
    int32_t sum_cost[N] = {0};
    int32_t backptr[N]  = {0};

    sum_cost[1] = abs(h[1] - h[0]);
    rep(i, 2, N){
        jmp1 = sum_cost[i-1] + abs(h[i] - h[i-1]);
        jmp2 = sum_cost[i-2] + abs(h[i] - h[i-2]);
        if(jmp1 < jmp2){
            sum_cost[i] = jmp1;
            backptr[i] = i - 1;
        } else{
            sum_cost[i] = jmp2;
            backptr[i] = i - 2;
        }
    }

    N -= 1;
    stack<int32_t> optjmp;
    while(N > 0){
        optjmp.push(N);
        N = backptr[N];
    }

    cout << optjmp.size() + 1 << endl;

    cout << 1;
    while(!optjmp.empty()){
        printf(" %d", optjmp.top() + 1);
        optjmp.pop();
    }
    cout << endl;
}