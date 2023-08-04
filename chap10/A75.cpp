// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define MAXD 1440

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 T[N + 1], D[N + 1];
    pi16 problems[N];
    rep(i, 0, N - 1){
        cin >> T[i + 1] >> D[i + 1];
        problems[i] = make_pair(D[i + 1], T[i + 1]);
    }

    sort(problems, problems + N);

    rep(i, 0, N - 1){
        D[i + 1] = problems[i].first;
        T[i + 1] = problems[i].second;
    }

    int table[N + 1][MAXD + 1];
    rep(j, 0, MAXD){
        table[0][j] = 0;
    }

    rep(i, 1, N){
        rep(j, 0, MAXD){
            if(j < T[i] || j > D[i]){
                table[i][j] = table[i - 1][j];
            } else{
                table[i][j] = max(
                    table[i - 1][j],
                    table[i - 1][j - T[i]] + 1
                );
            }
        }
    }

    int answer = 0;
    rep(j, 0, MAXD){
        answer = max(answer, table[N][j]);
    }
    cout << answer << endl;

    return(0);
}