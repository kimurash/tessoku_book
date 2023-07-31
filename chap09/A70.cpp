// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N, M;
    cin >> N >> M;

    i16 initial = 0, A;
    rep(i, 0, N - 1){
        cin >> A;
        initial += A << i;
    }

    i16 operation[M + 1]; // この値とXORを取る
    i16 X, Y, Z;
    rep(i, 1, M){
        cin >> X >> Y >> Z;
        operation[i] = (1 << (X - 1)) + (1 << (Y - 1)) + (1 << (Z - 1));
    }

    vector<i16> adjlst[1 << N];
    rep(i, 0, (1 << N) - 1){
        rep(j, 1, M){
            adjlst[i].push_back(i ^ operation[j]);
        }
    }

    i32 dist[1 << N];
    rep(i, 0, (1 << N) - 1){
        dist[i] = -1;
    }

    queue<i16> yet;
    yet.push(initial);
    dist[initial] = 0;

    while(!yet.empty()){
        i16 now = yet.front();
        yet.pop();
    
        for(i16 adj: adjlst[now]){
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                yet.push(adj);
            }
        }
    }

    cout << dist[(1 << N) - 1] << endl;
    return(0);
}