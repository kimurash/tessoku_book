#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define EPS 0.001

using namespace std;

int main(){
    int N;
    cin >> N;

    double left = 0, mid, right = 100.0;
    double fvalue, err = DBL_MAX;
    while(abs(err) > EPS){
        mid = (left + right) / 2.0;
        fvalue = pow(mid, 3.0) + mid;
        err = fvalue - 1.0 * N;

        if(err > 0){
            right = mid - EPS;
        } else{
            left = mid + EPS;
        }
    }

    cout << left << endl;
}