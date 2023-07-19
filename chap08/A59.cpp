// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

class SegmentTree{
    // セグメント木の要素数の上限
    // N以上で最小の2のべき+1乗とする
    static const int32_t MAX_NODE = 1 << 18;
    // 1始まりのセグメント木
    int32_t data[MAX_NODE];
public:
    int32_t range = 1; // セグメント木がカバーする配列の範囲

    /**
     * @param[in] N 配列の要素数
    */
    SegmentTree(int32_t N){
        while(this->range < N){
            this->range *= 2;
        }
        rep(i, 0, this->range * 2){
            data[i] = 0;
        }
    }

    /**
     * A[pos]をxで更新する
     * 
     * @param[in] pos 更新対象の配列の添字
     * @param[in] x   更新後の値
    */
    void update(int pos, int x){
        pos = pos + this->range - 1;
        this->data[pos] = x;
        while(pos > 1){
            pos /= 2;
            this->data[pos] = this->data[2 * pos] + this->data[2 * pos + 1];
        }
    }

    /**
     * [L, R]に対するクエリに答える
     * 
     * @param[in] l 求めたい区間の左端
     * @param[in] r 求めたい区間の右端
     * @param[in] a 節に対応する区間の左端
     * @param[in] b 節に対応する区間の右端
     * @param[in] u 現在の節番号
     * @return int32_t [L, R]に対するクエリの結果
    */
    int32_t query(int l, int r, int a, int b, int u){
        // ベースケース
        if(b < l || r < a){
            // 結果に影響しない値を返す
            return(0);
        }
        if(l <= a && b <= r){
            return(this->data[u]);
        }

        // 再帰ステップ
        int m = (a + b) / 2;
        return(
            this->query(l, r, a, m, 2 * u) +
            this->query(l, r, m + 1, b, 2 * u + 1)
        );
    }
};

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    SegmentTree segtree(N);

    int16_t qno;
    int32_t param1, param2;
    rep(i, 0, Q){
        cin >> qno >> param1 >> param2;
        switch(qno){
            case 1:
                segtree.update(param1, param2);
                break;
            case 2:
                cout << segtree.query(
                    param1, param2 - 1, 1, segtree.range, 1
                ) << endl;
                break;
        }
    }

    return(0);
}