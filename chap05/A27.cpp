#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t A, B;
    cin >> A >> B;

    if(A < B){
        swap(A, B);
    }

    int32_t r = A % B;
    while(r != 0){
        A = B;
        B = r;
        r = A % B;
    }

    cout << B << endl;
}