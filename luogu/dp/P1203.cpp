#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[710][2];
int main(){
    cin >> n;
    cin.ignore();
    getline(cin, s);
    s = s + s;
    int pos = 1;
    int len = (int)s.size();
    while(pos<=len-1){
        if(dp[pos-1][1]>0){
            dp[pos][1] = dp[pos-1][1]-1;
            pos++;
            continue;
        }
        for (int i = 1; i < len - pos;i++){
            if (s[pos] == s[pos + i] || s[pos  + i] == 'w')
                dp[pos][1]++;
            else break;
        }
        pos++;
    }
    int pr = len;
    while(pr>=1){
        if(dp[pr+1][0]>0){
            dp[pr][0] = dp[pr+1][0]-1;
            pr--;
            continue;
        }
        for (int i = 1; i <= pr-1;i++){
            if(s[pr-1]==s[pr-1-i] || s[pr-1-i] == 'w') dp[pr][0]++;
            else break;
        }
        pr--;
    }
    int ans = 0;
    for (int i = 1; i <= len;i++){
        ans = max(ans, dp[i][0] + dp[i][1]+2);
    }
        if( ans >= len/2){
            cout << len / 2 << endl;
            return 0;
        }
        else
            cout << ans << endl;
    
}