#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N], C[N];
    rep(i, 0, N){
        cin >> A[i];
        C[i] = A[i];
    }

    sort(C, C + N);

    int32_t B[N];
    int32_t old = -1, crrnt = 1;
    rep(i, 0, N){
        //int pos = lower_bound(A, A + N, C[i]) - A;
        int pos = distance(A, find(A, A + N, C[i]));

        if(C[i] == old){
            B[pos] = crrnt - 1;
        } else{
            B[pos] = crrnt++;
        }
        old = C[i];
        A[pos] = -1;
    }

    cout << B[0];
    rep(i, 1, N){
        cout << " " << B[i];
    }
    cout << endl;
}