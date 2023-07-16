// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t input, sum = 0;
    rep(i, 0, 3){
        cin >> input;
        sum += input;
    }

    if(sum == 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return(0);
}