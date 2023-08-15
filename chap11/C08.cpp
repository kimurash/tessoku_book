// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i16 judge(string first, string S);

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    string S[N]; i16 T[N];
    rep(i, 0, N - 1){
        cin >> S[i] >> T[i];
    }

    vector<string> candidate;
    rep(n, 0, 9999){
        string strn = to_string(n);
        while(strn.size() < 4){
            strn = "0" + strn;
        }

        bool flg = true;
        rep(i, 0, N - 1){
            i16 result = judge(strn, S[i]);
            if(result != T[i]){
                flg = false;
                break;
            }
        }

        if(flg){
            candidate.push_back(strn);
        }
    }

    if(candidate.size() > 1){
        // cout << candidate.size() << endl;
        cout << "Can't Solve" << endl;
    } else{
        cout << candidate[0] << endl;
    }

    return(0);
}

i16 judge(string first, string S){
    i16 cnt = 0;
    rep(i, 0, 3){
        if(first[i] != S[i]){
            cnt++;
        }
    }

    switch(cnt){
        case 0:
            return(1);
        case 1:
            return(2);
        default:
            return(3);
    }
}