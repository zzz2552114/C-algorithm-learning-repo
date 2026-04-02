#include <bits/stdc++.h>
using namespace std;
struct ggpos
{
    int x, y;
};

int main()
{
    int m, n;
    cin >> m >> n;
    // 1. 输入加工顺序
    vector<int> todo(m * n);
    for (int i = 0; i < m * n; i++)
    {
        cin >> todo[i];
        todo[i]--;
    }

    // 2. 输入工件-工序-机器映射
    vector<vector<int>> domachine(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> domachine[i][j];
            domachine[i][j]--; 
        }
    }

    // 3. 输入工件-工序-加工时间
    vector<vector<int>> dotime(n, vector<int>(m)); 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dotime[i][j];
        }
    }

    unordered_map<int, int> mp;
    vector<int> fpos(m, 0);
    vector<vector<ggpos>> cando(m, vector<ggpos>(400, {0, 0}));
    vector<int> gg(m, 0);
    vector<int> ipos(n, 0);
    // ------------------- 核心模拟循环 -------------------
    for (int i = 0; i < n * m; i++)
    {
        int job = todo[i];          // 当前要处理的工件
        int t = mp[job];            // 当前是工件job的第t道工序（0-based）
        mp[job]++;                  // 工序数+1
        int mc = domachine[job][t]; // 当前工序需要的机器
        int tmc = dotime[job][t];   // 当前工序的加工时间

        bool flag = false; // 标记是否成功插入空当
        int start = 0;     // 当前工序的实际开始时间
        int insert_z = -1; // 记录插入的空当位置（方便后续拆分）

        // 遍历机器mc的所有有效空当（0到gg[mc]-1）
        for (int z = 0; z < gg[mc]; z++)
        {
            // 计算空当的“可用开始时间”：
            // 既要 >= 空当的开始时间，又要 >= 工件上道工序的结束时间
            int available_start = max(cando[mc][z].x, ipos[job]);
            // 判断
            if (available_start + tmc <= cando[mc][z].y)
            {
                flag = true;
                start = available_start;
                insert_z = z;
                break; // 找到合适的空当就退出，不用再找后面的
            }
        }

        if (flag)
        {
            int old_start = cando[mc][insert_z].x;
            int old_end = cando[mc][insert_z].y;

            if (start == old_start && start + tmc == old_end)
            {
                // 情况1.1：空当被完全占用
                cando[mc][insert_z] = cando[mc][gg[mc] - 1];
                gg[mc]--;
            }
            else if (start == old_start)
            {
                // 情况1.2：只用了空当的前半部分
                cando[mc][insert_z].x = start + tmc;
            }
            else if (start + tmc == old_end)
            {
                // 情况1.3：只用了空当的后半部分
                cando[mc][insert_z].y = start;
            }
            else
            {
                // 情况1.4：用了空当的中间部分
                // 第一个空当：原来的开始到当前的开始
                cando[mc][insert_z].y = start;
                // 第二个空当：当前的结束到原来的结束（放到gg[mc]的位置）
                cando[mc][gg[mc]].x = start + tmc;
                cando[mc][gg[mc]].y = old_end;
                gg[mc]++; // 空当数+1
            }

            // 更新工件的上道工序结束时间
            ipos[job] = start + tmc;
            continue;
        }
        else
        {
            // 计算开始时间
            start = max(ipos[job], fpos[mc]);
            // 如果机器的可用时间 < 开始时间，说明中间产生了新空当
            if (fpos[mc] < start)
            {
                cando[mc][gg[mc]].x = fpos[mc]; // 空当开始：机器原来的可用时间
                cando[mc][gg[mc]].y = start;    // 空当结束：当前任务的开始时间
                gg[mc]++;                       // 空当数+1
            }

            // 更新机器的可用时间（往后推tmc）
            fpos[mc] = start + tmc;
            // 更新工件的上道工序结束时间
            ipos[job] = start + tmc;
        }
    }

    int maxi = fpos[0];
    for (int x : fpos)
    {
        if (x > maxi)
        {
            maxi = x;
        }
    }
    cout << maxi << endl;
    return 0;
}