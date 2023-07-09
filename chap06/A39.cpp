#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef pair<int32_t, int32_t> pi32;

bool comp(pi32 a, pi32 b){
    return(a.second < b.second);
}

int main(){
    int32_t N;
    cin >> N;

    int32_t L, R;
    vector<pi32> movie;

    rep(i, 0, N){
        cin >> L >> R;
        movie.push_back(make_pair(L, R));
    }

    sort(all(movie), comp);

    int32_t count = 1;
    int32_t end_time = movie[0].second;
    rep(i, 1, N){
        if(end_time <= movie[i].first){
            end_time = movie[i].second;
            count++;
        }
    }

    cout << count << endl;
}