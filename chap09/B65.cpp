// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXNODE 100'009

using namespace std;

int32_t N, T;
int32_t dist[MAXNODE];
stack<int32_t> visit_order;

void prep_visit_order(vector<int32_t> *adjlst);

int main(){
    cin >> N >> T;

    int32_t A, B;
    vector<int32_t> adjlst[N + 1];
    rep(i, 1, N - 1){
        cin >> A >> B;
        adjlst[A].push_back(B);
        adjlst[B].push_back(A);
    }

    prep_visit_order(adjlst);

    int32_t subordinate[N + 1] = {0};
    while(!visit_order.empty()){
        int32_t now = visit_order.top();
        visit_order.pop();

        for(int32_t adj: adjlst[now]){
            if(dist[adj] < dist[now]){
                subordinate[adj] = max(
                    subordinate[adj],
                    subordinate[now] + 1
                );
            }
        }
    }

    cout << subordinate[1];
    rep(i, 2, N){
        printf(" %d", subordinate[i]);
    }
    cout << endl;

    return(0);
}

void prep_visit_order(vector<int32_t> *adjlst){
    rep(i, 1, N){
        dist[i] = -1;
    }
    
    queue<int32_t> yet;
    yet.push(T);
    dist[T] = 0;
    
    while(!yet.empty()){
        int32_t now = yet.front();
        yet.pop();
    
        for(int32_t adj: adjlst[now]){
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                visit_order.push(adj);
                yet.push(adj);
            }
        }
    }
}