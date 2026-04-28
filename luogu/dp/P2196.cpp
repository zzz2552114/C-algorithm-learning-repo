#include<bits/stdc++.h>
using namespace std;
int n,arr[25],mp[25][25],dp[25],path[25];
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i <= n - 1;i++)
        for (int j = 1; j <= n - i;j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n;i++){ // 对于每一个地方
        for (int j = 1; j < i;j++){ // 看看前面有没有通路
            if(mp[j][i-j]){
                if(dp[i] < dp[j] + arr[i]){
                    dp[i] = dp[j] + arr[i];
                    path[i] = j;
                }
            }
        }  
    }
    int maxl = dp[1],pos = 1;
    for (int i = 2; i <= n;i++){
        if(maxl < dp[i]) {
            maxl = dp[i];
            pos = i;
        }
    }
    vector<int> ans;
    ans.push_back(pos);
    for (int i = pos; path[i] != 0;){
        ans.push_back(path[i]);
        i = path[i];
    }
    for (int i = (int)ans.size() - 1; i >= 0;i--){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    cout << maxl;
}
