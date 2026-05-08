#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int r, c;
        int mp[105][105],dp[105][105];
        memset(mp, 0, sizeof(mp));
        memset(dp, 0, sizeof(dp));
        cin >> r >> c;
        for (int i = 1; i <= r;i++)
            for (int j = 1; j <= c;j++)
                cin >> mp[i][j];
        for (int i = 1; i <= r;i++){
            for (int j = 1; j <= c;j++){
                if(i==1) dp[i][j] = dp[i][j-1]+mp[i][j];
                else if(j==1) dp[i][j] = dp[i-1][j]+mp[i][j];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + mp[i][j];
            }
        }
        cout << dp[r][c] << '\n';
    }
}

