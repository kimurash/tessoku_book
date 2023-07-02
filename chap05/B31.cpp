// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t N;
    cin >> N;

    int64_t N3  = N / 3;
    int64_t N5  = N / 5;
    int64_t N7  = N / 7;

    int64_t N15 = N / 15;
    int64_t N21 = N / 21;
    int64_t N35 = N / 35;

    int64_t N105 = N / 105;

    cout << (N3 + N5 + N7) - (N15 + N21 + N35) + N105 << endl;
}