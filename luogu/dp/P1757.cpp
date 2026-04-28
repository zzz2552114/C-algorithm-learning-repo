#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int w[1010], v[1010], s[1010];
int dp[1010];
int main(){
    cin >> m >> n;
    vector<int> vec;
    for (int i = 1; i <= n;i++){
        cin >> w[i] >> v[i] >> s[i];
        if(s[i]!=s[i-1]) vec.push_back(i);
    }
    int k = s[n];

    for (int i = 1; i <= k;i++){
        for (int j = m;j>=0; j--){
            int pos = vec[i - 1];
            while(pos<=n && s[pos]==i){
                if(j>=w[pos]) dp[j] = max(dp[j],dp[j-w[pos]]+v[pos]);
                pos++;
            }
        }
    }
    cout << dp[m] << endl;
}