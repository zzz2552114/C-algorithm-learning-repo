#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    cout << len << endl;
    cout << s[0] << "\n" << s[len-1] << endl;
    return 0;
}