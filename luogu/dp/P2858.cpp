#include<iostream>
using namespace std;
int n, arr[2005];
long long dp[2005][2005];
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        scanf("%d",&arr[i]);
        dp[i][i] = arr[i] * n;
    }
    for (int len = 2; len <= n;len++){
        int day = n - len+1;
        for (int i = 1; i+len-1 <= n;i++){
            int j = i + len - 1;
            dp[i][j] = max(dp[i + 1][j] + arr[i] * day, dp[i][j - 1] + arr[j] * day);
        }
    }
    cout << dp[1][n];
}