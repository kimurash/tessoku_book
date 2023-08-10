// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 159
#define ITER_MAX 200'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

i16 N;
pi16 city[MAXN];

i16 rand_i16(i16 a, i16 b);
double rand_double();
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

    double best_score = calc_score(path);
    rep(t, 1, ITER_MAX){
        i16 left  = rand_i16(1, N - 1);
        i16 right = rand_i16(1, N - 1);
        if(left > right){
            swap(left, right);
        }

        reverse(path + left, path + right + 1);

        double score = calc_score(path); // 小さい方が好ましい
        if(score < best_score){ // スコアが改善する
            best_score = score;
        } else{ // スコアが悪化する
            double T = 30.0 - (28.0 * t) / ITER_MAX;
            double prob = exp((best_score - score) / T);
            if(rand_double() < prob){
                best_score = score;
            } else{
                reverse(path + left, path + right + 1);
            }
        }
    }

    rep(i, 0, N){
        cout << path[i] << endl;
    }

    return(0);
}

i16 rand_i16(i16 a, i16 b){
    return(a + rand() % (b - a + 1));
}

double rand_double(){
    return((1.0 * rand()) / RAND_MAX);
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