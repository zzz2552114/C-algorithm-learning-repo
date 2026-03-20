#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    s[0] = toupper(s[0]);
    cout << s << endl;
    string s1 = "New String";
    s.replace(10, 20, s1, 0, 3);
    // 这里还是要注意一下语法，replace函数的参数分别是：要替换的字符串的起始位置，要替换的字符串的长度，要替换成的字符串，要替换成的字符串的起始位置，要替换成的字符串的长度
    cout << s << endl;
    s.erase(0, 1);
    // 这里同理
    cout << s << endl;
    s.clear();
    cout << s.length() << endl;
    cout << s.empty() << endl;
    return 0;
}
