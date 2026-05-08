#include<string>
#include<cstring>
#include<iostream>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size(), l2 = text2.size();
        int dp[l1 + 1][l2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                // 这里思路是dp[i][j]表示截止到“第1个str的第i个字母 && 第2个str的第j个字母”
                // 状态转移：选第i个第j个(前提是相等），只选某一个，都不选，取最大。但是实际上不是这么写状态转移的。
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        return dp[l1][l2];
    }
};