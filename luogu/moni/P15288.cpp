#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, k;
    cin >> t;
    vector<unordered_multiset<int>> vec(t);
    vector<vector<int>> temp(t);
    vector<pair<int, int>> data(t);
    for (int i = 0; i < t; i++)
    {
        cin >> data[i].first >> data[i].second;
        for (int j = 0; j < data[i].first; j++)
        {
            cin >> k;
            if (!vec[i].count(k))
            {
                temp[i].push_back(k);
            }
            vec[i].emplace(k);
        }
    }
    for (int i = 0; i < t; i++)
    {
        vector<int> cnt;
        for (int x : temp[i])
        {
            cnt.push_back(vec[i].count(x));
        }
        int result = cnt[0];
        for (int l = 1; l < (int)cnt.size(); l++)
        {
            result = gcd(result, cnt[l]);
        }
        int ori = data[i].first / result;
        int pos = ori;
        int ans = 0;
        while (pos <= data[i].second)
        {
            ans++;
            pos = ori * (ans + 1);
        }
        cout << ans << '\n';
    }
}