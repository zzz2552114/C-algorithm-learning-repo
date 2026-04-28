#include<bits/stdc++.h>
using namespace std;
// 先埃式筛预处理再dp
int n = 1000;
long long dp[1001];
bool nprime[1001];
int main(){
    // 第一步：埃式筛
    for (int i = 2; i <= n;i++){
        if(!nprime[i]){
            dp[i] = 0;
            for (int j = i * i; j <= n;j+=i)
                nprime[j] = 1;
        }
    }
    // 第二步：dp 完全背包的dp，这里是选方案数，dp[i][j]表示考虑前i个数且容量为j时的方案数
    // 状态转移：第i个数选取0，1，2，3……m个的情况下的转移。如果第i个数选取了k次，就加上dp[i-1][j-k*v]这个方案数
    // 不难发现计算dp[i][j-v]的时候，如果第i个数选取k-1次，就加上dp[i-1][j-k*v]这个方案数，每个都如此，也就是计算dp[i][j-v]的时候已经相当于加过选取1，2，3……m个的方案数了，所以dp[i][j] = dp[i-1][j]+dp[i][j-v]即可，换成一维滚动数组也可以
    int k;
    cin >> k;
    dp[0] = 1;
    for (int i = 2; i <= k;i++){
        for (int j = i; j <= k;j++)
            if (!nprime[i])
                dp[j] += dp[j - i];
    }
    cout << dp[k] << endl;
}