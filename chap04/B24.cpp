#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int get_LIS(int32_t *A, int32_t N){
    int32_t tab[N+1], L[N+1];
    rep(i, 1, N + 1){
        L[i] = INT32_MAX;
    }

    int range = 0;
    rep(i, 1, N + 1){
        // A[i]以上の最小の要素
        int idx = lower_bound(L + 1, L + 1 + range, A[i]) - L;

        tab[i] = idx;
        L[idx] = A[i];
        if(idx > range){
            range++;
        }
    }

    return(range);
}

int main(){
    int32_t N;
    cin >> N;

    pi32 box[N];
    int32_t X, Y;
    rep(i, 0, N){
        cin >> X >> Y;
        // Xが等しい場合はYの大きい順にソートするためマイナスをかける
        box[i] = make_pair(X, -Y);
    }

    sort(box, box + N);

    int32_t A[N+1];
    rep(i, 1, N + 1){
        A[i] = -box[i-1].second;
    }

    cout << get_LIS(A, N) << endl;
}