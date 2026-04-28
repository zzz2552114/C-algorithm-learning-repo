#include<bits/stdc++.h>
using namespace std;
int v,n;
int arr[35];
int dp[20010];
int main(){
    cin >> v >> n;
    for (int i = 1; i <= n;i++) cin >> arr[i];

    for (int i = 1; i <= n;i++){
        for (int j = v; j >=0 ; j--)
            if(j>=arr[i]) dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
    }
    cout << v-dp[v] << endl;
}