#include<bits/stdc++.h>
using namespace std;
char method[105];
long long nums[105], dpmax[105][105], dpmin[105][105];
int main(){
    int n;
    cin >> n;
    memset(dpmax, 0xc0, sizeof(dpmax));
    memset(dpmin, 0x7f, sizeof(dpmin));
    for (int i = 1; i <= n;i++){
        cin >> method[i] >> nums[i];
        nums[n+i] = nums[i];
        method[n + i] = method[i];
        dpmax[i][i] = nums[i];
        dpmax[n + i][n + i] = nums[i];
        dpmin[i][i] = nums[i];
        dpmin[n + i][n + i] = nums[i];
    }

    // t t x x t  t x x
    // -7 4 2 5 -7 4 2 5
    // 区间dp，结果是i=1~4，j = 4~7的结果
    // dp[1][2] =
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= 2*n-len+1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (method[k + 1] == 't'){
                    dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j]);
                    dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j]);
                }
                else{
                    
                    long long a = dpmax[i][k] * dpmax[k + 1][j];
                    long long b = dpmax[i][k] * dpmin[k + 1][j];
                    long long c = dpmin[i][k] * dpmax[k + 1][j];
                    long long d = dpmin[i][k] * dpmin[k + 1][j];
                    dpmax[i][j] = max({dpmax[i][j], a, b, c, d});
                    dpmin[i][j] = min({dpmin[i][j], a, b, c, d});
                    
                }
                    
            }
        }
        }
        long long maxl = LLONG_MIN;
        for (int i = 1; i <= n; i++)
            maxl = max(maxl, dpmax[i][i + n - 1]);
        cout << maxl << '\n';
        for (int i = 1; i <= n; i++)
            if (dpmax[i][i + n - 1] == maxl)
                cout << i << ' ';

}