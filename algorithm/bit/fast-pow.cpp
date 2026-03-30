#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
ll power()
{
    // 位运算可以简化幂次的迭代次数 用判断次数换迭代次数 这很神奇
    int temp = n, ans = 1;
    while (k)
    {
        if (k & 1)
        {
            ans *= temp;
        }
        temp *= temp;
        k = k >> 1;
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    cout << power() << endl;
}