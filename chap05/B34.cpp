// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    int16_t X, Y;
    cin >> N >> X >> Y;

    int16_t xor_sum = 0;
    int16_t grundy[] = {0, 0, 1, 1, 2};
    int64_t A;
    rep(i, 0, N){
        cin >> A;
        xor_sum ^= grundy[A % 5];
    }

    if(xor_sum != 0){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
}