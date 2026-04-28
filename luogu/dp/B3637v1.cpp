#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5010];
vector<int> dp(5010,1);
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    for (int i = 1; i <= n;i++){
        for(int j = 1;j<i;j++){
            if(arr[i]>arr[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}