#include<iostream>
#include<algorithm>
using namespace std;
int n, w;
int arr[1010];
long long dp[10010],mod = 1e9+7;
int main(){
    cin >> n >> w;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }

    dp[0] = 1;
    for (int j = 1; j <= w;j++){
        for (int i = 1; i <= n;i++){
            if(j>=arr[i]) dp[j]+=dp[j-arr[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[w];
}