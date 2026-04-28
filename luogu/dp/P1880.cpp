#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, arr[205],dpmax[205][205],pref[205];
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = n + 1; i <= 2*n - 1;i++){
        arr[i] = arr[i - n];
        pref[i] = pref[i - 1] + arr[i];
    }
    vector<vector<int>> dpmin(205, vector<int>(205, 1e7));
    for (int i = 0; i <= 204;i++) dpmin[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= 2*n-1; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k <= j; k++)
            { // 这里定义从k左边切一刀
                dpmin[i][j] = min(dpmin[i][j], dpmin[i][k - 1] + dpmin[k][j] + pref[j] - pref[i - 1]);
                dpmax[i][j] = max(dpmax[i][j], dpmax[i][k - 1] + dpmax[k][j] + pref[j] - pref[i - 1]);
            }
        }
    }
    int minl = dpmin[1][n], maxl = dpmax[1][n];
    for (int i = 2; i <= n;i++){
        minl = min(minl, dpmin[i][i + n - 1]);
        maxl = max(maxl, dpmax[i][i + n - 1]);
    }
        cout << minl << '\n'
             << maxl << endl;
}