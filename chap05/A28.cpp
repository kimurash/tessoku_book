// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MOD 10000

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    char oprator;
    int64_t A, answer = 0;
    rep(i, 0, N){
        cin >> oprator >> A;
        switch(oprator){
            case '+':
                answer += A;
                break;
            case '-':
                answer -= A;
                break;
            case '*':
                answer *= A;
                break;
        }

        answer %= MOD;
        if(answer < 0){
            answer += MOD;
        }

        cout << answer << endl;
    }
}