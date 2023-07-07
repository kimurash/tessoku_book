// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    char state;
    int32_t num_on = 0;
    rep(i, 0, N){
        cin >> state;
        if(state == '1'){
            num_on++;
        }
    }

    if((num_on & 1) == (K & 1)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}