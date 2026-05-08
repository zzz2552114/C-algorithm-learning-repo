#include<bits/stdc++.h>
using namespace std;
int n, m, t,dp[205][205],arr[105][2];
int main(){
    cin >> n >> m >> t;
    for (int i = 1; i <= n;i++) cin >> arr[i][0] >> arr[i][1];
    for (int i = 1;i<=n;i++){
        for (int j = m;j>=arr[i][0];j--){
            for (int p = t; p >= arr[i][1];p--){
                dp[j][p] = max(dp[j][p], dp[j - arr[i][0]][p - arr[i][1]] + 1);
            }
        }
    }
    cout << dp[m][t];
}