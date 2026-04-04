#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n, k,arr[maxN],anser;

void checker(int l)
{
    if (l == 2)
    {
        anser++;
        return;
    }
    for (int i = 2; i <= sqrt(l); i++)
    {
        if (l % i == 0)
        {
            return;
        }
    }
    anser++;
}

void dfs(int j, int start, int ans)
{ // 这里的i表示第i个数位
    if(j>=k){
        if (ans == 1) return;
        checker(ans);
        return;
    }
    for (int m = start; m < n;m++){
        ans += arr[m];
        dfs(j + 1, m + 1, ans);
        ans -= arr[m];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }// 输入完毕
    dfs(0,0,0);
    cout << anser << endl;
}