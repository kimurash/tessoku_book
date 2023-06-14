#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    rep(i, 0, N){ cin >> A.at(i); }

    sort(all(A));
    int left = 0, middle, right = N-1;
    while(left <= right){
        middle = (left + right) / 2;
        if(A.at(middle) < X){
            left = middle + 1;
        } else if(A.at(middle) > X){
            right = middle - 1;
        } else{
            break;
        }
    }

    cout << middle + 1 << endl;
}