#include<iostream>
#include<algorithm>
using namespace std;
int n, w, arr[1010];
long long dp[10010];
int main(){
    cin >> n >> w;
    for (int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    // 方案数完全背包问题
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= w;j++){
            if(j>=arr[i]){
                dp[j] += dp[j-arr[i]];
                dp[j] %= 1000000007;
            }
        }
    }
    cout << dp[w] << endl;
}