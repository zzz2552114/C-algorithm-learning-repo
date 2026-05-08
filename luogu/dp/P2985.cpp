#include<iostream>
#include<algorithm>
using namespace std;
int n, d;
int arr[50010];
int ans[50010];

bool check(long long mid){
    int pos = 1;
    long long k = 0;
    for (int i = 1; i <= d;i++){
        while(k<mid){
            if(pos > n) return 0;
            k += arr[pos++];
        }
        k /= 2;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    long long l = 0, r = 1e11;
    while(l<r){
        long long mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << '\n';
    int pos = 1;
    long long k = 0;
    for (int i = 1; i <= d;i++){
        while (k < l)
        {
            k += arr[pos];
            ans[pos++] = i;
        }
        k /= 2;
    }
    while(pos<=n) ans[pos++] = d;
    for (int i = 1; i <= n;i++) cout<< ans[i] << '\n';
}
