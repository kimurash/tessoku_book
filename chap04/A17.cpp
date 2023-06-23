#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N], B[N] = {0};
    rep(i, 1, N){ cin >> A[i]; }
    rep(i, 2, N){ cin >> B[i]; }

    int32_t path1, path2;
    int32_t travel[N] = {0}, backptr[N] = {0};

    travel[1] = A[1];
    rep(i, 2, N){
        path1 = travel[i-1] + A[i];
        path2 = travel[i-2] + B[i];
        if(path1 < path2){
            travel[i] = path1;
            backptr[i] = i-1;
        } else{
            travel[i] = path2;
            backptr[i] = i-2;
        }
    }

    int32_t room = N - 1;
    stack<int32_t> optpath;
    while(room > 0){
        optpath.push(room);
        room = backptr[room];
    }

    cout << optpath.size() + 1 << endl;

    cout << 1;
    while(!optpath.empty()){
        printf(" %d", optpath.top() + 1);
        optpath.pop();
    }
    cout << endl;
}