#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int ans = 0;
        set<char> st{'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; i++)
            if (st.count(s[i]))
                ans++;
        int temp = ans;
        for (int i = 1, j = k; j < (int)s.size(); i++, j++)
        {
            if (st.count(s[i - 1]))
                temp--;
            if (st.count(s[j]))
                temp++;
            ans = max(temp, ans);
        }
        return ans;
    }
};