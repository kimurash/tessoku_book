// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ELEMENT 20 // 配列Xの要素数
#define ITER 100 // 操作の回数

#define WIDTH 10000 // ビーム幅

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef struct pqr{
    i16 p;
    i16 q;
    i16 r;
} PQR;

typedef struct state{
    i16 X[ELEMENT + 1];
    i16 score; // 累積スコア
    char last_opr; // どの操作で遷移したか
    i16 last_rank; // どの順位から遷移したか
} State;

PQR pqr[ITER + 1]; // 操作対象の添字
int num_state[ITER + 1]; // t回目の操作で生成された状態の数
State beam[ITER + 1][WIDTH];

void beam_search(i16 T);

bool operator>(const State& a, const State& b){
    return(a.score > b.score);
}

int main(){
    cin.tie(nullptr);

    i16 T;
    cin >> T;

    rep(i, 1, T){
        cin >> pqr[i].p >> pqr[i].q >> pqr[i].r;
    }

    beam_search(T);

    // beamはscoreの降順にソートされているためbeam[T][0]のscoreが最大
    i16 crrnt = 0;
    for(int t = T; t > 0; t--){
        if(beam[t][crrnt].last_opr == 'A'){
            cout << "A" << endl;
        }else{
            cout << "B" << endl;
        }
        crrnt = beam[t][crrnt].last_rank;
    }

    return(0);
}

void beam_search(i16 T){
    rep(i, 1, ELEMENT){
        beam[0][0].X[i] = 0;
    }
    beam[0][0].score = 0;

    num_state[0] = 1; // 最初は状態数1

    rep(t, 1, T){ // t回目の操作
        vector<State> candidate;
        rep(s, 0, num_state[t - 1] - 1){ // 1つ前の状態s
            // 操作Aで遷移した場合
            State state_a = beam[t - 1][s];
            state_a.X[pqr[t].p] += 1;
            state_a.X[pqr[t].q] += 1;
            state_a.X[pqr[t].r] += 1;
            state_a.last_opr = 'A';
            state_a.last_rank = s;
            rep(i, 1, ELEMENT){
                if(state_a.X[i] == 0){
                    state_a.score += 1;
                }
            }

            // 操作Bで遷移した場合
            State state_b = beam[t - 1][s];
            state_b.X[pqr[t].p] -= 1;
            state_b.X[pqr[t].q] -= 1;
            state_b.X[pqr[t].r] -= 1;
            state_b.last_opr = 'B';
            state_b.last_rank = s;
            rep(i, 1, ELEMENT){
                if(state_b.X[i] == 0){
                    state_b.score += 1;
                }
            }

            candidate.push_back(state_a);
            candidate.push_back(state_b);
        }

        // 解候補をscoreの降順にソート
        sort(all(candidate), greater<State>());

        // 上位num_state[t]個の状態を記録する
        num_state[t] = min(WIDTH, (int)candidate.size());
        rep(s, 0, num_state[t] - 1){
            beam[t][s] = candidate[s];
        }
    }

    return;
}