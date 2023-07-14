// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    int32_t A[N];
    rep(i, 0, N){
        A[i] = i + 1;
    }

    int16_t qno;
    int32_t x, y;
    bool reversed = false;
    rep(i, 0, Q){
        cin >> qno;
        switch(qno){
            case 1:
                cin >> x >> y;
                if(reversed){
                    A[N - x] = y;
                } else{
                    A[x - 1] = y;
                }
                break;
            case 2:
                reversed = !reversed;
                break;
            case 3:
                cin >> x;
                if(reversed){
                    cout << A[N - x] << endl;
                } else{
                    cout << A[x - 1] << endl;
                }
                break;
        }
    }

    return(0);
}