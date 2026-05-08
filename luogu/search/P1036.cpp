#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
int n, k,arr[25],ans;
bool check(int i){
    if(i==1) return 0;
    for (int j = 2; j * j <= i;j++)
        if(i%j==0) return 0;
    return 1;
}
void dfs(int t,int sum,int cnums){
    if(cnums==k){
        if(check(sum)) ans++;
        return;
    }
    if(k-cnums>n+1-t) return;
    else{
        dfs(t + 1, sum,cnums);
        dfs(t + 1, sum + arr[t],cnums+1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    dfs(1,0,0);
    cout << ans;
}