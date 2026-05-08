#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c;
int mp[105][105], dp[105][105];

struct node
{
    int x, y;
};
vector<node> dir{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dfs(node curr)
{
    if (dp[curr.x][curr.y])
        return dp[curr.x][curr.y];
    dp[curr.x][curr.y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nxtx = curr.x + dir[i].x;
        int nxty = curr.y + dir[i].y;
        if (nxtx >= 1 && nxty >= 1 && nxtx <= r && nxty <= c && mp[nxtx][nxty] < mp[curr.x][curr.y])
            dp[curr.x][curr.y] = max(dp[curr.x][curr.y], dfs({nxtx, nxty}) + 1);
    }
    return dp[curr.x][curr.y];
}
int main()
{
    cin >> r >> c;
    int minp = 1e9;
    node start;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> mp[i][j];
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, dfs({i, j}));
    cout << ans;
}