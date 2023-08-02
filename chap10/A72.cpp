// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define rall(v) v.rbegin(), v.rend()
#define MAXH 19
#define MAXW 109

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

i16 H, W, K;
char grid[MAXH][MAXW];

void paint_row(i16 row){
    rep(j, 1, W){
        grid[row][j] = '#';
    }
}

void paint_col(i16 col){
    rep(i, 1, H){
        grid[i][col] = '#';
    }
}

i32 count_black(){
    i32 cnt = 0;
    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '#'){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin.tie(nullptr);

    cin >> H >> W >> K;
    char c[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> c[i][j];
        }
    }

    i32 answer = 0;
    for (int b = 0; b < (1 << H); b++) {
        rep(i, 1, H){
            rep(j, 1, W){
                grid[i][j] = c[i][j];
            }
        }

        i16 remain = K;
        bitset<10> bs(b);
        if(bs.count() > remain){
            continue;
        }

        rep(i, 0, H - 1){
            if(bs.test(i)){
                paint_row(i + 1);
                remain--;
            }
        }

        if(K > 0){
            vector<pi16> col_white_cnt;
            rep(j, 1, W){
                i16 cnt = 0;
                rep(i, 1, H){
                    if(grid[i][j] == '.'){
                        cnt++;
                    }
                }
                col_white_cnt.push_back(make_pair(cnt, j));
            }

            sort(rall(col_white_cnt));

            i16 idx = 0;
            while(remain > 0 && idx < col_white_cnt.size()){
                paint_col(col_white_cnt[idx++].second);
                remain--;
            }
        }

        answer = max(answer, count_black());
    }

    cout << answer << endl;
    return(0);
}