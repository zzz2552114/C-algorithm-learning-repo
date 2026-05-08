#include<iostream>
#include<algorithm>
using namespace std;
int mp[105][105];
int dp[105][55][55];
int main(){
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            cin >> mp[i][j];
    for (int k = 2; k <= m + n-1;k++){
        for (int i1 = 2; i1 <= min(k,n);i1++){
            for (int i2 = 1; i2 < i1;i2++){
                dp[k][i1][i2] = max({dp[k - 1][i1 - 1][i2 - 1], dp[k - 1][i1 - 1][i2], dp[k - 1][i1][i2 - 1], dp[k - 1][i1][i2]}) + mp[k - i1 + 1][i1] + mp[k - i2 + 1][i2];
            }
        }
    }
    cout << dp[m + n - 2][n][n - 1];
}