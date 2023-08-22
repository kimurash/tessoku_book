// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXTIME 200'000 // 86400 * 2より大きければよい

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

i32 cnt_before[MAXTIME], cnt_after[MAXTIME];
i32 acc_before[MAXTIME], acc_after[MAXTIME];

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    i32 L[N], R[N];
    rep(i, 0, N - 1){
        cin >> L[i] >> R[i];
        R[i] += K;
    }

    vector<pi32> early_end(N);
    rep(i, 0, N - 1){
        early_end[i] = make_pair(R[i], L[i]);
    }
    sort(early_end.begin(), early_end.end());

    i32 now = 0;
    rep(i, 0, early_end.size() - 1){
        if(now <= early_end[i].second){
            now = early_end[i].first;
            cnt_before[now]++;
        }
    }

    vector<pi32> late_start(N);
    rep(i, 0, N - 1){
        late_start[i] = make_pair(L[i], R[i]);
    }
    sort(late_start.rbegin(), late_start.rend());

    now = MAXTIME;
    rep(i, 0, late_start.size() - 1){
        if(now >= late_start[i].second){
            now = late_start[i].first;
            cnt_after[now]++;
        }
    }

    rep(i, 1, MAXTIME - 1){
        acc_before[i] = acc_before[i - 1] + cnt_before[i];
        int j = (MAXTIME - 1) - i;
        acc_after[j] = acc_after[j + 1] + cnt_after[j];
    }

    rep(i, 0, N - 1){
        cout << acc_before[L[i]] + 1 + acc_after[R[i]] << endl;
    }

    return(0);
}