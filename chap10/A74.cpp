// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 bubble_sort(i16 *arr, i16 N){
    i32 cnt = 0;
    rep(i, 0, N - 2){
        for(int j = N - 1; j > i; j--){
            if(arr[j - 1] > arr[j]){
                swap(arr[j - 1], arr[j]);
                cnt++;
            }
        }
    }
    return(cnt);
}

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 P;
    i16 row[N], column[N];
    rep(i, 0, N - 1){
        rep(j, 0, N - 1){
            cin >> P;
            if(P != 0){
                row[i] = P;
                column[j] = P;
            }
        }
    }

    cout << bubble_sort(row, N) + bubble_sort(column, N) << endl;
    return(0);
}