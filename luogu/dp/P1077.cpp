#include<iostream>
using namespace std;
int n, m, arr[105];
long long dp[105][105];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;

    // 这是分组背包的题目,先把每个ai分成2的幂次的加和
    // 这里突然发现是求方案数，这么拆会重复，只能便利每个了
    // 数据范围不大，100的三次方，100万的数据，直接开最容易理解的二维数组即可
    for (int i = 1; i <= n; i++)
    {// 遍历每一盆花
        for (int j = 1; j <= m; j++)
        {// 遍历每一个容量
            for (int k = 0; k <= arr[i]; k++)
            {// 遍历第i盆花选k个
                if (j < k)
                    break;
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= 1000007;
            }
        }
    }
    cout << dp[n][m] << endl;
}