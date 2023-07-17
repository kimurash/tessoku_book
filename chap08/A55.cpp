// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int32_t Q;
    cin >> Q;

    int16_t qno;
    int32_t x;
    set<int32_t> table;
    rep(i, 0, Q){
        cin >> qno >> x;
        switch(qno){
            case 1:
                table.insert(x);
                break;
            case 2:
                table.erase(x);
                break;
            case 3:
                auto itr = lower_bound(all(table), x);
                if(itr == table.end()){
                    cout << -1 << endl;
                } else{
                    cout << (*itr) << endl;
                }
                break;
        }
    }

    return(0);
}