// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXNODE 100'009
#define MAXCOST 10'000

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int32_t dist[MAXNODE];
bool locked[MAXNODE];

void dijkstra(vector<pi32> *adjlst);

int main() {
    int32_t N, M;
    cin >> N >> M;

    int32_t A, B, C;
    vector<pi32> adjlst[N + 1];
    rep(i, 1, M) {
        cin >> A >> B >> C;
        adjlst[A].push_back(make_pair(B, C));
        adjlst[B].push_back(make_pair(A, C));
    }

    rep(i, 1, N) {
        // 辺数の最大値 = 頂点数の最大値であるためMAXNODEで代替
        dist[i] = MAXCOST * MAXNODE;
        locked[i] = false;
    }

    dijkstra(adjlst);

    rep(i, 1, N) {
        if(locked[i]){
            cout << dist[i] << endl;
        } else{
            cout << -1 << endl;
        }
    }

    return (0);
}

void dijkstra(vector<pi32> *adjlst) {
    priority_queue<pi32, vector<pi32>, greater<pi32>> Q;
    Q.push(make_pair(0, 1));

    int32_t now, mindist;
    while (!Q.empty()) {
        // Qから未確定頂点が現れるまで取り出す
        tie(mindist, now) = Q.top(); Q.pop();
        if (locked[now]) {
            continue;
        }

        // 最短距離を確定する
        dist[now] = mindist;
        locked[now] = true;

        for (pi32 adj: adjlst[now]) {
            int32_t to = adj.first;
            int32_t w = adj.second;

            if (locked[to]) {  // 確定済み
                continue;
            }

            // 隣接する頂点の距離を更新する
            if (mindist + w < dist[to]) {
                dist[to] = mindist + w;
                Q.push(make_pair(dist[to], to));
            }
        }
    }

    return;
}