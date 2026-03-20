#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1;
    string s2;
    cin >> s1 >> s2;
    string s3 = s1 + s2;
    s1 += s2;
    cout << s3 << endl;
    cout << s1 << endl;
    return 0;
}