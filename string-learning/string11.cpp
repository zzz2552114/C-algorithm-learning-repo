#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cout << "输入一个字符串：" << endl;
    getline(cin, s);
    int len = s.length();
    cout << "字符串s的长度为：" << len << endl;
    /*
    reverse(s.begin(), s.end());
    这是逆序最好的办法，这里面s.begin()的返回值是一个地址（也就是一个指针），而且这个指针可以自己往后计算地址
    那么实际上&s[0]也是一个可以往后计算的地址
    而且C++现在支持&s[len]这种越界写法，因为这是右边取不到的
    */

    reverse(&s[0], &s[len]);
    /*    
    下面是手写的for循环逆序
    string res_s(len, '\0');
    for (int i = 0; i < len; i++)
    {
        res_s[i] = s[len - i -1];
    }
    cout << "逆序后的字符：" << endl
         << res_s << endl;
    */

    cout << "逆序后的字符：" << endl
         << s << endl;

    int upper_count = 0;
    int lower_count = 0;
    int num_count = 0;
    int space_count = 0;
    int other_count = 0;
    // 记住下面这一坨isupper,islower,isspace,isdigit吧。返回bool值。
    // 相似的还有toupper转换
    for (char x : s)
    {
        if (isupper(x))
        {
            upper_count += 1;
        }
        else if (islower(x))
        {
            lower_count += 1;
        }
        else if (isdigit(x))
        {
            num_count += 1;
        }
        else if (isspace(x))
        {
            space_count += 1;
        }
        else
        {
            other_count += 1;
        }
    }
    cout << "大写" << upper_count << endl;
    cout << "小写" << lower_count << endl;
    cout << "数字" << num_count << endl;
    cout << "空格" << space_count << endl;
    cout << "其他" << other_count << endl;
    return 0;
}