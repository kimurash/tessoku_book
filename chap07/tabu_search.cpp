// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define MAXN 159
#define ITER_MAX 200'000
#define TABU_SIZE 15

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

i16 N;
pi16 city[MAXN];

i16 rand_between(i16 a, i16 b);
double calc_dist(i16 a, i16 b);
double calc_score(i16 *path);

int main(){
    cin.tie(nullptr);

    cin >> N;
    rep(i, 1, N){
        cin >> city[i].first >> city[i].second;
    }

    i16 path[N + 1];
    rep(i, 0, N - 1){
        path[i] = i + 1;
    }
    path[N] = 1;

    i16 left;
    i16 right;
    list<i16> tabu_list;
    double best_score = calc_score(path);

    rep(i, 1, ITER_MAX){
        do{
            left  = rand_between(1, N - 1);
            right = rand_between(1, N - 1);
            if(left > right){
                swap(left, right);
            }
        } while(find(all(tabu_list), left) != tabu_list.end());

        tabu_list.push_back(left);
        if(tabu_list.size() >= TABU_SIZE){
            tabu_list.pop_front();
        }

        reverse(path + left, path + right + 1);

        double score = calc_score(path);
        if(score < best_score){
            best_score = score;
        } else{
            reverse(path + left, path + right + 1);
        }
    }

    rep(i, 0, N){
        cout << path[i] << endl;
    }

    return(0);
}

i16 rand_between(i16 a, i16 b){
    return(a + rand() % (b - a + 1));
}

double calc_dist(i16 a, i16 b){
    return sqrt(
        pow(city[a].first - city[b].first, 2) +
        pow(city[a].second - city[b].second, 2)
    );
}

double calc_score(i16 *path){
    double score = 0;
    rep(i, 0, N - 1){
        score += calc_dist(path[i], path[i + 1]);
    }
    return(score);
}