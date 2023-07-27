// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

struct Edge{
public:
    int32_t from;
    int32_t to;
    int32_t weight;

    bool operator<(const Edge &e) {
        return (this->weight < e.weight);
    }
};

class UnionFind{
private:
    static const int32_t MAX_NODE = 100'009; // Union-Find木の頂点数の上限
    int32_t parent[MAX_NODE]; // 各頂点の親
    int32_t size[MAX_NODE];   // 各頂点を根とする木の頂点数
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
private:
    // 頂点xの根を求める
    int32_t root(int32_t x){
        while(parent[x] != -1){
            x = parent[x];
        }
        return(x);
    }
};


int main(){
    cin.tie(nullptr);
    
    i32 N, M;
    cin >> N >> M;

    i32 A, B, C;
    Edge edge[M];
    rep(i, 0, M - 1){
        cin >> A >> B >> C;
        edge[i] = {A, B, C};
    }

    sort(edge, edge + M);

    i64 answer = 0;
    UnionFind uf = UnionFind(N);
    rep(i, 0, M - 1){
        if(uf.same(edge[i].from, edge[i].to)){
            continue;
        } else{
            uf.unite(edge[i].from, edge[i].to);
            answer += edge[i].weight;
        }
    }

    cout << answer << endl;
    return(0);
}