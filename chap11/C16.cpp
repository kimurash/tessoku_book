// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

#define MAX 100'009
#define MAXTIME 2'000'000'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

typedef struct flight{
    i32 src; // 出発する空港の番号
    i32 dst; // 到着する空港の番号
    i32 depart; // 出発時刻
    i32 arrive; // 到着時刻
} Flight;

typedef enum vert_type{
    DPT, ARV, AIRPORT
} vtype;

typedef struct vert{
    i32 time;
    i32 idx; // フライトまたは空港の連番
    vtype type;
} Vert;

typedef struct edge{
    i32 src; // 出発する頂点の番号
    i32 dst; // 到着する頂点の番号
} Edge;

Flight flight[MAX];
vector<Vert> vert;
Edge edge[MAX];
vector<i32> airport[MAX];

bool comp(Vert &a, Vert &b){
    return(a.time < b.time);
}

int main(){
    cin.tie(nullptr);

    i32 N, M, K;
    cin >> N >> M >> K;

    rep(i, 1, M){
        cin >> flight[i].src >> flight[i].depart;
        cin >> flight[i].dst >> flight[i].arrive;
        flight[i].arrive += K;
    }

    // 時間の昇順にソート
    rep(i, 1, M){
        vert.push_back({flight[i].depart, i, DPT});
        vert.push_back({flight[i].arrive, i, ARV});
    }
    rep(i, 1, N){
        vert.push_back({0, i, AIRPORT}); // 左端
        vert.push_back({MAXTIME, i, AIRPORT}); // 右端
    }
    sort(all(vert), comp);

    // 時間の昇順に頂点番号を割り当てる
    // 0とvert.size() + 1は始点と終点に割り当てる
    rep(i, 0, vert.size() - 1){
        switch(vert[i].type){
            case ARV:
                edge[vert[i].idx].dst = i + 1;
                airport[flight[vert[i].idx].dst].push_back(i + 1);
                break;

            case DPT:
                edge[vert[i].idx].src = i + 1;
                airport[flight[vert[i].idx].src].push_back(i + 1);
                break;

            case AIRPORT:
                airport[vert[i].idx].push_back(i + 1);
                break;
        }
    }

    // グラフを構築する
    // 飛行機に乗る
    vector<pi32> adjlst[2 * (N + M) + 9];
    rep(i, 1, M){
        adjlst[edge[i].src].push_back(make_pair(edge[i].dst, 1));
    }

    // 空港で待つ
    rep(i, 1, N){
        rep(j, 0, airport[i].size() - 2){
            i32 ahead = airport[i][j];
            i32 behind = airport[i][j + 1];
            adjlst[ahead].push_back(make_pair(behind, 0));
        }
    }

    // グラフに始点と終点を加える
    rep(i, 1, N){
        adjlst[0].push_back(make_pair(airport[i][0], 0));
        adjlst[airport[i][airport[i].size() - 1]].push_back(make_pair(vert.size() + 1, 0));
    }

    i32 table[vert.size() + 2];
    table[0] = 0;
    rep(i, 1, vert.size() + 1){
        table[i] = 0;
    }

    rep(i, 0, vert.size()){
        for(pi32 adj: adjlst[i]){
            table[adj.first] = max(table[adj.first], table[i] + adj.second);
        }
    }

    cout << table[vert.size() + 1] << endl;
    return(0);
}