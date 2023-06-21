#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_CMB 32768
#define MAX_BIT 15

using namespace std;

int main(){
    int32_t N, K;
    cin >> N >> K;

    int32_t l = N / 2;
    int32_t r = N - l;

    int32_t L[l], R[r];
    rep(i, 0, l){ cin >> L[i]; }
    rep(i, 0, r){ cin >> R[i]; }

    int64_t X[MAX_CMB] = {0}, Y[MAX_CMB] = {0};
    // l <= rが成り立つため
    for (int b = 0; b < (1 << r); b++) {
        bitset<MAX_BIT> bs(b);
        int64_t xsum = 0, ysum = 0;
        rep(i, 0, r){
            if(bs.test(i)){
                if(i < l){
                    xsum += L[i];
                }
                ysum += R[i];
            }
        }
        X[b] = xsum; // i >= lのときは0が代入される
        Y[b] = ysum;
    }

    rep(i, 0, 1 << l){
        rep(j, 0, 1 << r){
            if(X[i] + Y[j] == K){
                cout << "Yes" << endl;
                return(0);
            }
        }
    }

    cout << "No" << endl;
}