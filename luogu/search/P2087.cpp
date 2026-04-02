#include <bits/stdc++.h>
using namespace std;
int n,pos = 0,ans = 0;
vector<int> arr(10);
vector<vector<int>> ansarr;
// 把搜索树画出来了基本上就清晰了
void dfs(int i){ // 这里的i表示第几个调料（树的第几层）
    if(i == 10) {
        if(pos == n){
            ans++;
            ansarr.push_back(arr);
            // for(int x:arr){
            //     cout << x << ' ';
            // }
            // cout << endl;
            return;
        }else {
            return;
        }
    }
    if(pos == n && i != 10) return;
    for (int j = 1; j <= 3;j++){
        if(pos+j<=n){
            pos += j;
            arr[i] = j;
            dfs(i + 1);
            pos -= j;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n > 30 || n<10){
        cout << 0 << endl;
        return 0;
    }
    dfs(0);
    cout << ans << endl;
    for (int p = 0; p < ans;p++){
        for (int q = 0; q < 10;q++){
            cout << ansarr[p][q] << ' ';
        }
        cout << endl;
    }
}