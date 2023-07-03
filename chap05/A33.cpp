// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A;
    int32_t nim_sum = 0;
    rep(i, 0, N){
        cin >> A;
        nim_sum ^= A;
    }

    if(nim_sum == 0){
        cout << "Second" << endl;
    } else{
        cout << "First" << endl;
    }
}