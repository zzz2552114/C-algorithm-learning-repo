#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> mp[i][j];
        }
    }// 完成了输入
    vector<int> cg{0, 1, -1};
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mp[i][j] == '*')
                continue;
            for(int x:cg)
            {
                if(i+x>=0 && i+x<n)
                {
                    for (int y:cg)
                    {
                        if(j+y>=0&&j+y <m)
                        {
                            if(mp[i+x][j+y]=='*')
                                cnt++;
                        }
                    }
                }
            }
            mp[i][j] = (char)('0' + cnt);
            cnt = 0;
        }    
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
}