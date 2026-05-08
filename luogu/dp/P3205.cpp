#include<bits/stdc++.h>
using namespace std;
int arr[1010];
long long dp[1010][1010][2];
const int mod = 19650827;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
    }
    // 时间复杂度只有n^2能接受
    // 题目分析：任意子时刻组成的序列必定是最终序列的连续子序列，且下一个插入的人必定是最终序列中该子序列的左/右边
    // 状态设计：dp[i][j][0] && dp[i][j][1] 这表示i,j子序列且最后一个人由左/右插入，值为此时的方案数
    // 状态转移，这个简单依据题目模拟即可

    // 区间dp先枚举长度
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if(arr[i]<arr[i+1])
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % mod;
            if(arr[i]<arr[j])
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % mod;
            if(arr[j]>arr[i])
                dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][0]) % mod;
            if(arr[j]>arr[j-1])
                dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1]) % mod;
        }
    }
    cout << (dp[1][n][0] + dp[1][n][1]) % mod;
}