#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s1;
int dp[1005][1005];
int main(){
    getline(cin, s1);
    string s2 = s1;
    reverse(s1.begin(), s1.end());
    int l1 = (int)s1.size();
    for (int i = 1; i <= l1;i++){
        for (int j = 1; j <= l1;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s1[i-1] == s2[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout << l1 - dp[l1][l1];
}
