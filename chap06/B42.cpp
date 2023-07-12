// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t A[N], B[N];
    rep(i, 0, N){
        cin >> A[i] >> B[i];
    }

    int64_t max_score = 0;
    rep(mode, 0, 4){
        int64_t front = 0, back = 0;
        rep(i, 0, N){
            bool select = false;
            switch(mode){
                case 0:
                    if(A[i] + B[i] > 0){
                        select = true;
                    }
                    break;
                case 1:
                    if(A[i] - B[i] > 0){
                        select = true;
                    }
                    break;
                case 2:
                    if(-A[i] + B[i] > 0){
                        select = true;
                    }
                    break;
                case 3:
                    if(-A[i] - B[i] > 0){
                        select = true;
                    }
                    break;
            }

            if(select){
                front += A[i];
                back  += B[i];
            }
        }

        max_score = max(max_score, abs(front) + abs(back));
    }

    cout << max_score << endl;
    return(0);
}