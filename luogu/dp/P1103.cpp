#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
vector<vector<int>> book(105,vector<int>(2));
int dp[105][105];
bool cmp(const vector<int> a,const vector<int> b){
    return a[0] < b[0];
}
int main(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> book[i][0] >> book[i][1];
    }
    sort(book.begin(), book.begin() + n + 1, cmp);
    for (int i = 1; i <= n;i++){
        dp[i][i] = 0;
        dp[i][0] = dp[i - 1][0] + abs(book[i][1] - book[i - 1][1]);
        dp[i][i - 1] = 0;
    }
    if(k == n-1){
        cout << 0;
        return 0;
    }
    // 状态设计，dp[i][j]表示只考虑前i本书时去掉j本的最小度,且保留第i本书
    // 状态转移，遍历t，dp[t][j-(i-1-t)]是保留t，去掉t~i-1的情况
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= min(i - 2, k); j++)
        {
            for (int t = i - 1; t >= i - 1 - j; t--)
            {
                dp[i][j] = min(dp[i][j], dp[t][j-i+1+t] + abs(book[i][1] - book[t][1]));
            }
        }
    }
    int ans = dp[n][k];
    for (int i = n-1; i >= n-k;i--){
        ans = min(ans, dp[i][k - n + i]);
    }
    cout << ans << endl;
}