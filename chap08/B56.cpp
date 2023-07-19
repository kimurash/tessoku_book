// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAXLEN 100'000
#define MOD 1'000'000'011

using namespace std;

int64_t hash_tab_fwd[MAXLEN];
int64_t hash_tab_rev[MAXLEN];
int64_t pow100[MAXLEN];

void make_hash_tab(string S);
int64_t calc_hash(bool type, int32_t l, int32_t r);

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;
    make_hash_tab(S);

    int32_t L, R;
    rep(i, 0, Q){
        cin >> L >> R;
        if(calc_hash(true, L - 1, R - 1) == calc_hash(false, S.length() - R, S.length() - L)){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }

    return(0);
}

void make_hash_tab(string S){
    pow100[0] = 1;
    hash_tab_fwd[0] = S[0] - 'a';
    hash_tab_rev[0] = S[S.length() - 1] - 'a';

    rep(r, 1, S.length()){
        hash_tab_fwd[r] = (100LL * hash_tab_fwd[r - 1] + (S[r] - 'a')) % MOD;
        hash_tab_rev[r] = (100LL * hash_tab_rev[r - 1] + (S[S.length() - 1 - r] - 'a')) % MOD;
        pow100[r] = (100LL * pow100[r - 1]) % MOD;
    }
}

int64_t calc_hash(bool type, int32_t l, int32_t r){
    int64_t *hash_tab;
    if(type){ // true => fwd
        hash_tab = hash_tab_fwd;
    } else{ // false => rev
        hash_tab = hash_tab_rev;
    }

    int64_t hash = hash_tab[r];
    if(l > 0){
        hash -= (pow100[r - l + 1] * hash_tab[l - 1]) % MOD;
        if(hash < 0){
            hash += MOD;
        }
    }
    return(hash);
}
