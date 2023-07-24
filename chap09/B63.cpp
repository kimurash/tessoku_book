// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXRC 59

using namespace std;

typedef pair<int16_t, int16_t> pi16;

int16_t R, C;
int16_t sy, sx, gy, gx;
char maze[MAXRC][MAXRC];

int16_t dx[] = {1, 0, -1, 0};
int16_t dy[] = {0, 1, 0, -1};

int16_t bfs();

int main(){
    cin >> R >> C;
    cin >> sy >> sx >> gy >> gx;

    rep(i, 1, R){
        rep(j, 1, C){
            cin >> maze[i][j];
        }
    }

    cout << bfs() << endl;
    return(0);
}

int16_t bfs(){
    int16_t dist[R + 1][C + 1];
    rep(i, 1, R){
        rep(j, 1, C){
            dist[i][j] = -1;
        }
    }

    queue<pi16> yet;
    yet.push(make_pair(sy, sx));
    dist[sy][sx] = 0;

    int16_t y, x, ny, nx;
    while(!yet.empty()){
        tie(y, x) = yet.front();
        yet.pop();

        if(y == gy && x == gx){
            return(dist[y][x]);
        }

        rep(i, 0, 3){
            ny = y + dy[i];
            nx = x + dx[i];

            if(dist[ny][nx] == -1 && maze[ny][nx] != '#'){
                dist[ny][nx] = dist[y][x] + 1;
                yet.push(make_pair(ny, nx));
            }
        }
    }

    // never reached
    return(dist[gy][gx]);
}