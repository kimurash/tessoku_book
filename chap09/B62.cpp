// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define MAXNODE 100'009

using namespace std;

int32_t N;
bool visited[MAXNODE];
stack<int32_t> history;

bool search_path(vector<int32_t> *adjlst, int32_t now);

int main(){
    int32_t M;
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

    history.push(1);
    search_path(adjlst, 1);

    vector<int32_t> path;
    while(!history.empty()){
        path.push_back(history.top());
        history.pop();
    }

    reverse(all(path));

    cout << path[0];
    rep(i, 1, path.size() - 1){
        printf(" %d", path[i]);
    }
    cout << endl;
    
    return(0);
}

bool search_path(vector<int32_t> *adjlst, int32_t now){
    if(now == N){
        return(true);
    }

    visited[now] = true;

    for(int32_t to: adjlst[now]){
        if(!visited[to]){
            history.push(to);
            if(search_path(adjlst, to)){
                return(true);
            }
            history.pop();
        }
    }

    return(false);
}