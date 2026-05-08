#include<iostream>
#include<algorithm>
using namespace std;
struct datas{
    int x, y;
};
int n;
datas arr[150010];
long long dp[3000010];
bool cmp(datas a,datas b){
    return a.x < b.x;
}
int main(){
    cin >> n;
    int uppest = 0;
    for (int i = 1; i <= n;i++){
        cin >> arr[i].x >> arr[i].y;
        uppest = max(uppest, arr[i].y);
    }
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= uppest;j++)
        {
            if (j >= arr[i].y){
                dp[j] = max(dp[j], dp[arr[i].x-1] + arr[i].y - arr[i].x + 1);
            }
        }
    }
    cout << dp[uppest];
}