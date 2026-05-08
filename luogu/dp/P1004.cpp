#include<iostream>
#include<algorithm>
using namespace std;
int dp[20][12][12],mp[12][12];
int main(){
    int n;
    cin >> n;
    int i, j, v;
    while(cin >> i >> j >> v,i || j || v){
        mp[i][j] = v;
    }
    // 思路很特殊，考虑两次路一起走，走过的路数记为k，然后i1,i2即可，dp的值表示最大和。然后状态转移
    // 状态转移：如果i1==i2那么路重合，只加一次
    // 这里暂时有个疑问，i1和i2都不应该大于k;
    dp[1][1][1] = mp[1][1];
    for (int k = 2; k <= 2 * n - 1;k++){
        for (int i1 = 1; i1 <= min(k,n);i1++){
            for (int i2 = 1; i2 <= min(k,n);i2++){
                if(i1!=i2)
                    dp[k][i1][i2] = max({dp[k - 1][i1 - 1][i2], dp[k - 1][i1 - 1][i2 - 1], dp[k - 1][i1][i2 - 1], dp[k - 1][i1][i2]}) + mp[i1][k-i1+1]+mp[i2][k-i2+1];
                else
                    dp[k][i1][i2] = max({dp[k - 1][i1 - 1][i2], dp[k - 1][i1 - 1][i2 - 1], dp[k - 1][i1][i2 - 1], dp[k - 1][i1][i2]}) + mp[i1][k - i1 + 1];
            }
        }
    }
    cout << dp[2 * n - 1][n][n];
}