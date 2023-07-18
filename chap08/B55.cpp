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
    set<int32_t> table_pos;
    set<int32_t> table_neg;
    rep(i, 0, Q){
        cin >> qno >> x;
        switch(qno){
            case 1:
                table_pos.insert(x);
                table_neg.insert(-x);
                break;

            case 2:
                if(table_pos.size() == 0){
                    cout << -1 << endl;
                    break;
                }

                auto itr_pos = lower_bound(all(table_pos), x);
                auto itr_neg = lower_bound(all(table_neg), -x);

                if(itr_pos == table_pos.end()){
                    cout << (*itr_neg + x) << endl;
                } else{
                    if(itr_neg == table_neg.end()){
                        cout << (*itr_pos - x) << endl;
                    } else{
                        cout << min(*itr_pos - x, *itr_neg + x) << endl;
                    }
                }
                break;
        }
    }

    return(0);
}