#include<bits/stdc++.h>
using namespace std;
int vm, wm, n;
int v[55],w[55],c[55],dp[410][410];
// 先复习一下一维背包怎么写
/*
int main(){
    int dp[100];
    cin >> nums; // 这里表示货物数目
    for(int i = 1;i<=nums;i++)
        for(int j = maxV;j>=v[i];j--) // 套路是从大往小枚举这样可以保证滚动数组时是i-1
            dp[j] = max[dp[j],dp[j-v[i]]+arr[i]];
    // 这里是这样的：max后的dp[j]相当于上一轮（第i-1个物品）的j容量下的最好解，dp[j-v[i]]是上一轮j-v[i]下的最优解
    // 如果j<v[i]那么不变，自动相当于是上一轮的dp[j]
}
*/
int main(){
    cin >> vm >> wm >> n;
    for (int i = 1; i <= n;i++) cin >> v[i] >> w[i] >> c[i];
    // 这道题的二维背包也是同理
    for (int i = 1; i <= n;i++){
        for (int k = vm; k >= v[i];k--){
            for (int t = wm; t >= w[i];t--){
                dp[k][t] = max(dp[k][t], dp[k - v[i]][t - w[i]] + c[i]);
            }
        }
    }
    cout << dp[vm][wm] << endl;
}