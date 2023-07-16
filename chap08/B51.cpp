// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    string S;
    cin >>S;

    stack<int32_t> left;
    rep(i, 0, S.size()){
        switch(S[i]){
            case '(':
                left.push(i + 1);
                break;

            case ')':
                printf("%d %d\n", left.top(), i + 1);
                left.pop();
                break;
        }
    }

    return(0);
}