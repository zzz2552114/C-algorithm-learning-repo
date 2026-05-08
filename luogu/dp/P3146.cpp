#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[250],dp[250][250];
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i<=n;i++){
        cin >> arr[i];
        dp[i][i] = arr[i];
        // 这个题目是区间dp，正常的思路已经很接近了，但是这个题目还是有点特殊的，洛谷上的狠多题解都是有问题的
        // 状态表示：dp[i][j], i,j表示从i开始从j结束的闭区间，数值表示合成一个数后的数值，如果没法合成成为一个数，那么就为0
        // 状态转移：和正常区间dp一样枚举断点，O(N^3)
        ans = max(ans, arr[i]);
    }
    // 注意区间dp先枚举长度
    for (int len = 2; len <= n;len++){
        for (int i = 1; i+len-1 <= n ;i++){
            int j = i + len - 1;
            for (int k = i; k < j;k++){
                if(dp[i][k]>0 && dp[k+1][j]>0 && dp[i][k]==dp[k+1][j])
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}