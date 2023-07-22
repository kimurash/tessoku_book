// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXNODE 100'000

using namespace std;

bool visited[MAXNODE + 1];

void dfs(const vector<int32_t> *adjlst, int32_t u);

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

    rep(i, 1, N){
        visited[i] = false;
    }

    dfs(adjlst, 1);

    rep(i, 1, N){
        if(!visited[i]){
            cout << "The graph is not connected." << endl;
            return(0);
        }
    }

    cout << "The graph is connected." << endl;
    return(0);
}

void dfs(const vector<int32_t> *adjlst, int32_t u){
    visited[u] = true;

    for(int32_t adj: adjlst[u]){
        if(!visited[adj]){
            dfs(adjlst, adj);
        }
    }

    return;
}