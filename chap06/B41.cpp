// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int main(){
    int32_t X, Y;
    cin >> X >> Y;

    stack<pi32> history;
    while(X != 1 || Y != 1){
        history.push(make_pair(X, Y));
        if(X > Y){
            X -= Y;
        } else{
            Y -= X;
        }
    }

    cout << history.size() << endl;

    while(history.size() > 0){
        pi32 h = history.top();
        history.pop();
        printf("%d %d\n", h.first, h.second);
    }

    return(0);
}