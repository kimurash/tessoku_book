#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX 100009

using namespace std;

int N, K;
int A[MAX];

bool enough_printed(int time){
    long sum = 0;
    rep(i, 0, N){
        sum += floor(time / A[i]);
    }

    if(sum < K){
        return(false);
    } else{
        return(true);
    }
}

int main(){
    cin >> N >> K;
    rep(i, 0, N){ cin >> A[i]; }

    int left = 1, mid, right = 1'000'000'000;
    while(left < right){
        mid = (left + right) / 2;
        bool result = enough_printed(mid);
        if(result){ // K枚以上生産できる
            right = mid;
        } else{ // K枚生産できない
            left = mid + 1;
        }
    }

    cout << left << endl;
}