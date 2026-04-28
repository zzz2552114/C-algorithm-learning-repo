#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5010],dp[5010];
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++) cin>> arr[i];
    dp[1] = arr[1];
    int len = 2;
    for (int i = 2; i <= n;i++){
        auto it = lower_bound(dp, dp + len, arr[i]);
        if(*it == arr[i]) continue;
        if(it-dp==len) len++;
        *it = arr[i];
    }
    for (int j = 0;j<=n;j++) cout << dp[j] << ' ' ;
    cout << '\n';
    for (int k = 1; k <= n + 1; k++)
    {
        if (!dp[k])
        {
            cout << k - 1;
            break;
        }
        }
}