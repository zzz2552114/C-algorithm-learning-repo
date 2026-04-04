#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans = 1e5, pos = 0;
const int maxN = 210;
int arr[maxN], dist[maxN];
bool flag = false;

void dfs(int i)
{ // 这里的i表示第i楼，从第0楼开始
    if (i >= n || i < 0 || pos >= dist[i])
    {
        return;
    }
    dist[i] = pos;
    if (i == b - 1)
    {
        ans = pos;
        flag = true;
        return;
    }

    pos++;
    dfs(i + arr[i]);
    pos--;

    pos++;
    dfs(i - arr[i]);
    pos--;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } // 输入完成
    fill(dist, dist + maxN, 1e5);
    dfs(a - 1);
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}