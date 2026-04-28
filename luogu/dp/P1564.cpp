#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
short arr[2505];
int dp[2505],cnt[2505];
int main(){
    cin >> n>>m;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        if(arr[i]==2) cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1]-1;
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[1] = 1,dp[0] = 0;
    for (int i = 2; i <= n;i++){
        // 对于第i个人，找前面有没有可以切断的地方，把所有地方做一个枚举
        // dp[i]表示考虑前i个人最少可以开几个机房
        for (int j = 1; j <= i;j++){
            // 这里我规定是从第j个人左边切一刀和i分组
            if(abs(cnt[i]-cnt[j-1])<=m || abs(cnt[i]-cnt[j-1])==i-j+1)
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n];
}