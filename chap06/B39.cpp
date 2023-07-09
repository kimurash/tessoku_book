#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef pair<int32_t, int32_t> pi32;

bool comp(pi32 a, pi32 b){
    return(a.second > b.second);
}

int main(){
    int32_t N, D;
    cin >> N >> D;

    vector<pi32> work;
    int32_t X, Y;
    rep(i, 0, N){
        cin >> X >> Y;
        work.push_back(make_pair(X, Y));
    }

    sort(all(work), comp);

    int32_t sum = 0;
    rep(d, 1, D + 1){
        rep(i, 0, work.size()){
            if(work[i].first <= d){
                sum += work[i].second;
                work.erase(work.begin() + i);
                break;
            }
        }
    }

    cout << sum << endl;
}