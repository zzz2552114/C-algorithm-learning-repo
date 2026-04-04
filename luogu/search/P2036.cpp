#include <bits/stdc++.h>
using namespace std;
int n, ans = 1e5;
int sour[15], bitter[15];

void dfs(int i, int s, int b)
{
    if (i >= n && b == 0)
        return;
    if (i >= n && b > 0)
    {
        int tot = s - b;
        if (tot < 0)
            tot *= -1;
        ans = min(tot, ans);
        return;
    }
    dfs(i + 1, s * sour[i], b + bitter[i]);
    dfs(i + 1, s, b);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sour[i] >> bitter[i];
    } // ÊäÈëÍê³É
    dfs(0, 1, 0);
    cout << ans << endl;
}