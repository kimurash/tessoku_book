#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N){ cin >> A.at(i); }

    sort(all(A));

    int Q;
    cin >> Q;

    int pos, X;
    rep(i, 0, Q){
        cin >> X;
        pos = lower_bound(all(A), X) - A.begin();
        cout << pos << endl;
    }
}