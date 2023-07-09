// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    string S;
    cin >> N >> S;

    int16_t lt_bound[N];
    int16_t gt_bound[N];
    rep(i, 0, N){
        lt_bound[i] = gt_bound[i] = 1;
    }

    rep(i, 0, N - 1){
        if(S[i] == 'A'){
            lt_bound[i + 1] = lt_bound[i] + 1;
        }
        int j = (N - 2) - i;
        if(S[j] == 'B'){
            gt_bound[j] = gt_bound[j + 1] + 1;
        }
    }

    int32_t sum = 0;
    rep(i, 0, N){
        sum += max(lt_bound[i], gt_bound[i]);
    }
    cout << sum << endl;
}