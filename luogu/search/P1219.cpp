#include <bits/stdc++.h>
using namespace std;

int n;
int check[3][26];
int ansk[13], ans = 0;
void dfs(int line) // 这里line表示第几行
{
    if (line >= n)
    {
        ans++;
        if (ans <= 3)
        {
            for (int k = 0; k < n; k++)
            {
                cout << ansk[k] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[0][i] && !check[1][line + i] && !check[2][n + line - i])
        {
            /*
            写一下逻辑：check[0][i]检查第i列，check[1][line+i]检查斜率为-1的对角线，check[2][n+line-1]检查斜率为1的对角线
            */
            check[0][i] = 1;
            check[1][line + i] = 1;
            check[2][n + line - i] = 1;
            ansk[line] = i + 1;
            dfs(line + 1);
            check[0][i] = 0;
            check[1][line + i] = 0;
            check[2][n + line - i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << ans << endl;
}