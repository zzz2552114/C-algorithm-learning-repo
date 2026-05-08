#include<iostream>
#include<algorithm>
using namespace std;

int n, w, arr[100010];
long long ans;

bool check(long long mid){
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if(arr[i]-mid>0) cnt++;
    }
    if(cnt >= w) return 1;
    return 0;
}
int main(){
    cin >> n >> w;
    for (int i = 1; i <= n;i++){
        cin>>arr[i];
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1;i<=n;i++){
        arr[i] -= i - 1;
    }
    long long l = 0,r = 1e14;
    while(l<r){
        long long mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    long long x = l;
    if(check(l)) x++;
    ans = x * w;
    for (int i = 1; i <= n;i++){
        ans += max(arr[i] - x, (long long)0);
    }
    cout << ans;
    return 0;
}