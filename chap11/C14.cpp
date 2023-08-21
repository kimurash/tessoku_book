// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 100'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

i32 N;
bool locked[MAXN];
i32 dist_fwd[MAXN];
i32 dist_bwd[MAXN];

void dijkstra(vector<pi32> *adjlst, i32 start);

int main(){
    cin.tie(nullptr);

    i32 M;
    cin >> N >> M;

    vector<pi32> adjlst[N + 1];
    i32 A, B, C;
    rep(i, 1, M){
        cin >> A >> B >> C;
        adjlst[A].push_back(make_pair(B, C));
        adjlst[B].push_back(make_pair(A, C));
    }

    dijkstra(adjlst, 1);
    dijkstra(adjlst, N);

    i32 cnt = 0;
    i32 min_dist = dist_fwd[N];
    rep(i, 2, N - 1){
        if(dist_fwd[i] + dist_bwd[i] == min_dist){
            cnt++;
        }
    }

    cout << cnt + 2 << endl;
    return(0);
}

void dijkstra(vector<pi32> *adjlst, i32 start) {
    priority_queue<pi32, vector<pi32>, greater<pi32>> pq;
    pq.push(make_pair(0, start));

    i32 *dist;
    if(start == 1){
        dist = dist_fwd;
    } else if(start == N){
        dist = dist_bwd;
    } else {
        return;
    }

    rep(i, 1, N){
        dist[i] = 2'000'000'000;
        locked[i] = false;
    }

    int32_t now, mindist;
    while (!pq.empty()) {
        // pqから未確定頂点が現れるまで取り出す
        tie(mindist, now) = pq.top(); pq.pop();
        if (locked[now]) {
            continue;
        }

        // cout << "now:" << now << endl;

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