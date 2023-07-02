// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t N;
    cin >> N;

    int64_t N3  = N / 3;
    int64_t N5  = N / 5;
    int64_t N15 = N / 15;

    cout << N3 + N5 - N15 << endl;
}