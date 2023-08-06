// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 159

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint16_t ui16;

typedef pair<int16_t, int16_t> pi16;

pi16 city[MAXN];
bool visited[MAXN];

double calc_dist(i16 a, i16 b);

int main(){
    cin.tie(nullptr);

    ui16 N;
    cin >> N;

    rep(i, 1, N){
        cin >> city[i].first >> city[i].second;
    }

    vector<i16> path;
    i16 crrnt = 1;
    path.push_back(crrnt);
    visited[crrnt] = true;

    while(path.size() <= N){ // Nを符号付きで宣言すると警告が出る
        double min_dist = DBL_MAX;
        i16 nearest;

        rep(i, 1, N){
            if(visited[i]){
                continue;
            }

            double dist = calc_dist(crrnt, i);
            if(dist < min_dist){
                min_dist = dist;
                nearest = i;
            }
        }

        path.push_back(nearest);
        visited[nearest] = true;
        crrnt = nearest;
    }

    rep(i, 0, N - 1){
        cout << path[i] << endl;
    }
    cout << 1 << endl; // 最後に都市1に戻ってくる

    return(0);
}

double calc_dist(i16 a, i16 b){
    return sqrt(
        pow(city[a].first - city[b].first, 2) +
        pow(city[a].second - city[b].second, 2)
    );
}