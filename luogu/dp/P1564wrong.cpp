#include<iostream>
using namespace std;
int n, m,arr[2510],cnt[2510];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        if(arr[i] == 2) cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1] - 1;
    }
    int ans = 0;
    int pos = n, limit = m;
    while(pos>limit){
        if(cnt[pos]<=m && cnt[pos]>=-1*m){
            ans++;
            for (int j = pos+1; j <= n;j++) cnt[j] -= cnt[pos];
            limit = pos+m;
            pos = n;
            cout << "enter " << limit << ' ' << pos << '\n';
            continue;
        }
        pos--;
    }
    if(limit!=n+m){
        for (int i = limit-m+1; i <= n;i++){
            if(arr[i]!=arr[i+1]) ans++;
        }
    }
    cout << ans;
}