// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int32_t N, M;
    cin >> N >> M;

    int32_t A, B;
    vector<int32_t> adjlst[N + 1];
    rep(i, 1, M){
        cin >> A >> B;
        adjlst[A].push_back(B);
        adjlst[B].push_back(A);
    }

    rep(i, 1, N){
        printf("%d: {", i);
        rep(j, 0, adjlst[i].size() - 1){
            if(j != 0){
                cout << ", ";
            }
            cout << adjlst[i][j];
        }
        cout << "}" << endl;
    }
    
    return(0);
}
