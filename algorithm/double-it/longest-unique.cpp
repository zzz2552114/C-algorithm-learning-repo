#include <bits/stdc++.h>
using namespace std;
int main()
{
    /* 
    思想：
    放出快指针遍历，维护一个下标=值，值=次数的cnt数组
    如果cnt的val>1，计数快指针和慢指针之间的距离
    把慢指针拉到重复出现的数字的左一个
    并且要注意在慢指针的路上把经过数字的val清空
    */
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int i = 0, j = 0, ans = 0;
    vector<int> cnt(1e4);
    for (; j < n; j++)
    {
        cnt[vec[j]]++;
        if (cnt[vec[j]] > 1 || j == n - 1)
        {
            ans = max(ans, j - i);
            for (; i < j; i++)
            {
                if (vec[i] == vec[j])
                {
                    i++;
                    cnt[vec[i]] = 1;
                    break;
                }
                cnt[vec[i]] = 0;
            }
        }
    }
    cout << ans << endl;
    
}