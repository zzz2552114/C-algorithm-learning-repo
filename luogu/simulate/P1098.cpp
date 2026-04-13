#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3, pos = 0;
string s;

void solve()
{
    pos = s.find('-', pos);
    if (pos == string::npos)
        return;
    if (isdigit(s[pos - 1]) && isdigit(s[pos + 1]))
    {
        int t = s[pos + 1] - s[pos - 1];
        if (t <= 0)
        {
            pos++;
            return;
        }
        else if (t == 1)
        {
            s.erase(pos,1);
            return;
        }
        int len = (t - 1) * p2;
        string in(len, '*');
        if (p1 == 1 || p1 == 2)
        {
            for (int i = 0; i < len; i++)
            {
                in[i] = s[pos - 1] + ((i / p2) + 1);
            }
        }
        if (p3 == 2)
        {
            reverse(in.begin(), in.end());
        }
        s.erase(pos,1);
        s.insert(pos, in);
        return;
    }

    if (islower(s[pos - 1]) && islower(s[pos + 1]))
    {
        int t = s[pos + 1] - s[pos - 1];
        if (t <= 0)
        {
            pos++;
            return;
        }
        else if (t == 1)
        {
            s.erase(pos,1);
            return;
        }
        int len = (t - 1) * p2;
        string in(len, '*');
        if (p1 == 1)
        {
            for (int i = 0; i < len; i++)
            {
                in[i] = s[pos - 1] + ((i / p2) + 1);
            }
        }
        else if (p1 == 2)
        {
            for (int i = 0; i < len; i++)
            {
                in[i] = toupper(s[pos - 1] + ((i / p2) + 1));
            }
        }
        if (p3 == 2)
        {
            reverse(in.begin(), in.end());
        }
        s.erase(pos,1);
        s.insert(pos, in);

        return;
    }
    pos++;
}

int main()
{
    cin >> p1 >> p2 >> p3;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    while (pos != string::npos)
    {
        solve();
    }
    cout << s << endl;
}