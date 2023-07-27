// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

class UnionFind{
    static const int32_t MAX_NODE = 100'009; // Union-Find木の頂点数の上限
    int32_t parent[MAX_NODE]; // 各頂点の親
    int32_t size[MAX_NODE];   // 各頂点を根とする木の頂点数

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

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    UnionFind uf = UnionFind(N);

    int16_t qno;
    int32_t u, v;
    rep(i, 1, Q){
        cin >> qno >> u >> v;
        switch(qno){
            case 1:
                uf.unite(u, v);
                break;
            case 2:
                if( uf.same(u, v)){
                    cout << "Yes" << endl;
                } else{
                    cout << "No" << endl;
                }
                break;
        }
    }
    
    return(0);
}

