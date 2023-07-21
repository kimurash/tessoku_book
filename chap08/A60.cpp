// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int main(){
    int32_t N;
    cin >> N;

    int32_t price;
    stack<pi32> candidate;
    vector<int32_t> answer;
    rep(i, 0, N){
        cin >> price;

        while(true){
            if(candidate.empty()){
                answer.push_back(-1);
                break;
            }

            pi32 top = candidate.top();
            if(top.second > price){
                answer.push_back(top.first);
                break;
            }

            candidate.pop();
        }

        candidate.push(make_pair(i + 1, price));
    }

    cout << answer[0];
    rep(i, 1, N){
        printf(" %d", answer[i]);
    }
    cout << endl;

    return(0);
}