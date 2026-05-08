#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
int main(){
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        cnt += (k - arr[i]);
        if(cnt >= k){
            cout << 0;
            return 0;
        }
    }
    cout << k - cnt;
}