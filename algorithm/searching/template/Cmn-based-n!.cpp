// 给一个n，给一个m，m<=n，然后给出Cnm的排列
#include <bits/stdc++.h>
using namespace std;
// 按数位枚举
int n, m;

void dfs(int i, vector<int> &arr, vector<int> &nums)
{ // 这里的i是第几个数位
    if (i >= m)
    {
        for (int x : arr)
        {
            cout << x << ' ';
        }
        cout << endl;
        return;
    }
    int pos = 0, temp[n];
    for (int t = 0; t < n; t++)
    {
        if (nums[t])
        {
            arr[i] = nums[t];
            nums[t] = 0;
            temp[pos++] = t;
            dfs(i + 1, arr, nums);
        }
    }
    // 这里的回溯要注意，同级的一起删除，而不是谁探索完谁删除
    for (int m = 0; m < pos;m++){
        nums[temp[m]] = temp[m] + 1;
    }
}
int main()
{
    cin >> n >> m;
    vector<int> arr(m);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    dfs(0, arr, nums);
}