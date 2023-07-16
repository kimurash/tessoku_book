// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, X;
    cin >> N >> X;

    string A;
    cin >> A;

    queue<int32_t> Q;
    Q.push(X - 1);

    while(!Q.empty()){
        int32_t front = Q.front();
        Q.pop();
        A[front] = '@';

        if(front - 1 >= 0 && A[front - 1] == '.'){
            A[front - 1] = '@';
            Q.push(front - 1);
        }

        if(front + 1 < A.size() && A[front + 1] == '.'){
            A[front + 1] = '@';
            Q.push(front + 1);
        }
    }

    cout << A << endl;
    return(0);
}