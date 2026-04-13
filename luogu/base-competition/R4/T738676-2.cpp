#include<bits/stdc++.h>
using namespace std;

int t;
struct datas{
    int n;
    string s, t;
};
int arr[5][5];
int dp[5][1 << 5];

int dfs(int r,int l){
    if(r==5) return 0;
    if(dp[r][l]) return dp[r][l];
    int ans = 0;
    for (int j = 0; j < 5;j++){
        if(!(l&(1<<j))){
            ans = max(ans, dfs(r + 1, l | (1 << j)) + arr[r][j]);
        }
    }
    return dp[r][l] = ans;
}
int main(){
    cin >> t;
    vector<datas> vec(t);
    for (int i = 0; i < t;i++){
        cin >> vec[i].n >> vec[i].s >> vec[i].t;
    }
    for (int i = 0; i < t;i++){
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        vector<vector<int>> smp(5);
        vector<vector<int>> tmp(5);
        for (int pos = 0; pos < vec[i].n;pos++){
            switch (vec[i].s[pos]-'0'){
                case 0:
                    smp[0].push_back(pos);
                    break;
                case 1:
                    smp[1].push_back(pos);
                    break;
                case 2:
                    smp[2].push_back(pos);
                    break;
                case 3:
                    smp[3].push_back(pos);
                    break;
                case 4:
                    smp[4].push_back(pos);
                    break;
                }
            switch (vec[i].t[pos]-'0')
                {
                case 0:
                    tmp[0].push_back(pos);
                    break;
                case 1:
                    tmp[1].push_back(pos);
                    break;
                case 2:
                    tmp[2].push_back(pos);
                    break;
                case 3:
                    tmp[3].push_back(pos);
                    break;
                case 4:
                    tmp[4].push_back(pos);
                    break;
                }
        }
        for (int k = 0; k < 5;k++){
            for (int l = 0;l<5;l++){
                int spos = 0, tpos = 0;
                while(spos < (int)smp[k].size() && tpos < (int)tmp[l].size()){
                    if (smp[k][spos] == tmp[l][tpos]){
                        spos++;
                        tpos++;
                        arr[k][l]++;
                    }
                    else if(smp[k][spos] < tmp[l][tpos]) spos++;
                    else if(smp[k][spos]>tmp[l][tpos]) tpos++;
                }
            }
        }
        cout << dfs(0, 0) << '\n';
    }
}