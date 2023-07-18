// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAXLEN 200'000
#define MOD 2'000'000'011

using namespace std;

int64_t hash_tab[MAXLEN];
int64_t pow100[MAXLEN];

void make_hash_tab(string S);
int64_t calc_hash(int32_t l, int32_t r);

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;
    make_hash_tab(S);

    int32_t a, b, c, d;
    rep(i, 0, Q){
        cin >> a >> b >> c >> d;
        if(calc_hash(a - 1, b - 1) == calc_hash(c - 1, d - 1)){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }

    return(0);
}

void make_hash_tab(string S){
    pow100[0] = 1;
    hash_tab[0] = S[0] - 'a';

    rep(r, 1, S.length()){
        hash_tab[r] = (100LL * hash_tab[r - 1] + (S[r] - 'a')) % MOD;
        pow100[r] = (100LL * pow100[r - 1]) % MOD;
    }
}

int64_t calc_hash(int32_t l, int32_t r){
    int64_t hash = hash_tab[r];
    if(l > 0){
        hash -= (pow100[r - l + 1] * hash_tab[l - 1]) % MOD;
        if(hash < 0){
            hash += MOD;
        }
    }
    return(hash);
}
