// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXNODE 8009
#define SHIFT 10000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

bool locked[MAXNODE];
i64 dist[MAXNODE];

void dijkstra(vector<pi32> *adjlst);

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i16 D;
    i32 A, B, C;
    vector<pi32> adjlst[N + 1];
    rep(i, 1, M){
        cin >> A >> B >> C >> D;
        i32 cost = C * SHIFT;
        if(D == 1){
            cost -= 1;
        }

        adjlst[A].push_back(make_pair(B, cost));
        adjlst[B].push_back(make_pair(A, cost));
    }

    rep(i, 1, N){
        dist[i] = 1e12;
    }

    dijkstra(adjlst);

    i64 mindist = (dist[N] + (SHIFT - 1)) / SHIFT;
    printf("%ld %ld\n", mindist, mindist * SHIFT - dist[N]);

    return(0);
}

void dijkstra(vector<pi32> *adjlst) {
    priority_queue<pi32, vector<pi32>, greater<pi32>> pq;
    pq.push(make_pair(0, 1));

    int32_t now, mindist;
    while (!pq.empty()) {
        // pqから未確定頂点が現れるまで取り出す
        tie(mindist, now) = pq.top(); pq.pop();
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
                pq.push(make_pair(dist[to], to));
            }
        }
    }

    return;
}