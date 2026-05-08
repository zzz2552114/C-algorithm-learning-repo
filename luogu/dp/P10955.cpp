#include<bits/stdc++.h>
using namespace std;
long long dp[4005];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1;j<=n;j++){
            if(j>=i) dp[j] = (dp[j] + dp[j-i])%2147483648;
        }
    }
    cout << dp[n]-1;
}