// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    char C;
    int32_t N;
    cin >> N >> C;

    map<char, int16_t> color2score{
        {'W', 0},
        {'B', 1},
        {'R', 2},
    };

    char A;
    int32_t total = 0;
    rep(i, 0, N){
        cin >> A;
        total += color2score[A];
    }

    if(color2score[C] == (total % 3)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return(0);
}