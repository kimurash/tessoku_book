// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    if((K & 1) == 0 && (2 * N - 2 <= K)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}