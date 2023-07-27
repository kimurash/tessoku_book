// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXNODE 100'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

class UnionFind{
private:
    int32_t parent[MAXNODE]; // 各頂点の親
    int32_t size[MAXNODE];   // 各頂点を根とする木の頂点数

    // 頂点xの根を求める
    int32_t root(int32_t x){
        while(parent[x] != -1){
            x = parent[x];
        }
        return(x);
    }
public:
    UnionFind(int32_t N){
        rep(i, 1, N){
            this->parent[i] = -1; // 最初は親がない
            this->size[i] = 1;    // 最初はグループの頂点数が1
        }
    }

    // 節uと節vを統合する
    void unite(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        if(rootu == rootv){
            return;
        } else{
            if(this->size[rootu] < this->size[rootv]){
                this->parent[rootu] = rootv;
                this->size[rootv] += this->size[rootu];
            } else{
                this->parent[rootv] = rootu;
                this->size[rootu] += this->size[rootv];
            }
        }
    }

    // 節uと節vが同一のグループか判定する
    bool same(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        return(rootu == rootv);
    }
};

i16 qno[MAXNODE];
i32 x[MAXNODE], u[MAXNODE], v[MAXNODE];

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    UnionFind uf = UnionFind(N);

    i32 A, B;
    pi32 line[M + 1];
    bool canceled[M + 1];
    rep(i, 1, M){
        cin >> A >> B;
        line[i] = make_pair(A, B);
        canceled[i] = false;
    }

    i32 Q; cin >> Q;
    rep(i, 1, Q){
        cin >> qno[i];
        switch(qno[i]){
            case 1:
                cin >> x[i];
                canceled[x[i]] = true;
                break;
            case 2:
                cin >> u[i] >> v[i];
                break;
        }
    }

    // 最後まで残っている路線を結合する
    rep(i, 1, M){
        if(!canceled[i]){
            uf.unite(line[i].first, line[i].second);
        }
    }

    // クエリを逆から処理する
    vector<bool> answer;
    for(int q = Q; q > 0; q--){
        switch(qno[q]){
            case 1:
                uf.unite(line[x[q]].first, line[x[q]].second);
                break;
            case 2:
                if(uf.same(u[q], v[q])){
                    answer.push_back(true);
                } else{
                    answer.push_back(false);
                }
                break;
        }
    }

    for(int i = answer.size() - 1; i >= 0; i--){
        if(answer[i]){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }

    return(0);
}