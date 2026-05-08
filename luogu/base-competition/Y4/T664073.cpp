#include<bits/stdc++.h>
using namespace std;
int n,t,arr[1000010];
int main(){
    cin >> n >> t;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    // 滑动窗口问题
    long long ans = 0;
    for (int s = 1,f = 2; f <= n;s++,f++){
        if(max(arr[s],arr[f])<t)
            ans += t - max(arr[s], arr[f]);
    }
    cout << ans;
}