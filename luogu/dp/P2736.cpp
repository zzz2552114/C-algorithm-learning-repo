#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, tmax, mmax,arr[25],dp[25][25];
int main(){
    cin >> n >> tmax >> mmax;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    for (int sg = 1; sg <= n;sg++){
        for (int i = mmax; i >= 1; i--)
        { // 专辑一张一张地考虑,滚动数组的话要从大到小考虑
        /*
        状态设计，dp[i][j]表示在有i个专辑、每个专辑容量为j的时候能放下最多多少歌
        状态转移，对每一首歌，可以不取，可以放到这张专辑里面(如果时长还足够)，可以放到下一张专辑里
        */
            for (int t = tmax; t >= arr[sg]; t--)
            {
                dp[i][t] = max(dp[i][t], dp[i - 1][tmax] + 1);
                dp[i][t] = max(dp[i][t], dp[i][t - arr[sg]] + 1);
            }
        }
    }
    cout << dp[mmax][tmax];
}