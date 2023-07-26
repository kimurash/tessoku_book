// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define MAXNODE 100'009
#define MAXCOST 10'000

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int32_t dist[MAXNODE], before[MAXNODE];
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
        dist[i] = MAXCOST * MAXNODE;
        before[i] = 0;
        locked[i] = false;
    }

    dijkstra(adjlst);

    int32_t crrnt = N;
    vector<int32_t> path;
    do{
        path.push_back(crrnt);
        crrnt = before[crrnt];
    } while(crrnt > 0);

    reverse(all(path));

    cout << path[0];
    rep(i, 1, path.size() - 1){
        printf(" %d", path[i]);
    }
    cout << endl;

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

        for (pi32 to: adjlst[now]) {
            if (locked[to.first]) {  // 確定済み
                continue;
            }

            // 隣接する頂点の距離を更新する
            if (mindist + to.second < dist[to.first]) {
                dist[to.first] = mindist + to.second;
                Q.push(make_pair(dist[to.first], to.first));
                before[to.first] = now;
            }
        }
    }

    return;
}