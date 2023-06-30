#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t A, B;
    cin >> A >> B;

    if(A < B){
        swap(A, B);
    }

    int64_t p = A, q = B;
    int64_t r = p % q;
    while(r != 0){
        p = q;
        q = r;
        r = p % q;
    }

    printf("%ld\n", A * B / q);
}