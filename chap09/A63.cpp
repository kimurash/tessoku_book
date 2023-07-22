// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

int main(){
    int32_t N, M;
    cin >> N >> M;

    int32_t A, B;
    vector<int32_t> adjlst[N + 1];
    rep(i, 1, M){
        cin >> A >> B;
        adjlst[A].push_back(B);
        adjlst[B].push_back(A);
    }

    int32_t dist[N + 1];
    rep(i, 1, N){
        dist[i] = -1;
    }

    queue<int32_t> yet;
    yet.push(1);
    dist[1] = 0;

    while(!yet.empty()){
        int32_t now = yet.front();
        yet.pop();

        for(int32_t adj: adjlst[now]){
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                yet.push(adj);
            }
        }
    }

    rep(i, 1, N){
        cout << dist[i] << endl;
    }

    return(0);
}