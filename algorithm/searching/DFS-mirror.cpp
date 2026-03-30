#include <bits/stdc++.h>
using namespace std;
const int Max_x = 1e3 + 10, Max_y = 1e3 + 10;
int max_x, max_y, len = 0;
// 先构建起路径和坐标，坐标用结构体，路径用结构体为元素的数组
struct point
{
    int x, y;
};
stack<point> togo;
vector<vector<int>> gone(Max_x, vector<int>(Max_y, 0));
vector<point> direct{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool cg = false;
void pluss(vector<vector<int>> &mirror)
{
    point current = togo.top();
    len++;
    gone[current.x][current.y] = 1;
    cg = false;
    if (mirror[current.x][current.y] == 3)
    {
        cout << "找到一个路径，长度为:" << len << endl;
        return;
    }
    int cx = current.x;
    int cy = current.y;
    int nx, ny;
    // 按照当前位置的上下左右压栈
    for (point t : direct)
    {
        nx = cx + t.x;
        ny = cy + t.y;
        if (nx >= 0 && ny >= 0 && nx < max_x && ny < max_y && mirror[nx][ny] != 0 && gone[nx][ny] != 1)
        {
            point np{nx, ny};
            togo.emplace(np);
            cg = true;
        }
    }
}

int main()
{
    // 先输入迷宫再说

    cin >> max_x >> max_y;
    vector<vector<int>> mirror(max_x, vector<int>(max_y));
    for (int i = 0; i < max_x; i++)
    {
        for (int j = 0; j < max_y; j++)
        {
            cin >> mirror[i][j];
        } // 迷宫已经建立成功
    }
    togo.emplace(point{0, 0}); // 初始化压栈
    while (!togo.empty())
    {
        pluss(mirror); // 这里调用函数实现了：1.取栈顶(位移到栈顶) 2.标记栈顶走过 3.压栈栈顶附近的路
        if (cg == false)
        {
            // 看看回溯方法
            while (!togo.empty() && gone[togo.top().x][togo.top().y] == 1)
            {
                gone[togo.top().x][togo.top().y] = 0;
                togo.pop();
                len--;
            }
        }
    }
}