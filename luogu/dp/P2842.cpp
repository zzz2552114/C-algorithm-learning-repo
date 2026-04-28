#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int n, w, arr[1010];
long long dp[10010];
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    // 完全背包问题
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if(j>=arr[i]) dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    cout << dp[w] << endl;
}