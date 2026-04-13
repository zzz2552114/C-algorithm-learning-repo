#include <bits/stdc++.h>
using namespace std;
vector<string> mp(10);
unordered_set<int> st;
int hashval;

void run(int& x,int& y,int& dir){
    if(dir == 0){
        x--;
        if(x<0 || mp[x][y] == '*'){
            x++;
            dir += 1;
        }
        return;
    }
    else if (dir == 1)
    {
        y++;
        if (y>=10 || mp[x][y] == '*')
        {
            y--;
            dir += 1;
        }
        return;
    }
    else if (dir == 2)
    {
        x++;
        if (x >= 10 || mp[x][y] == '*')
        {
            x--;
            dir += 1;
        }
        return;
    }
    else if (dir == 3)
    {
        y--;
        if (y < 0 || mp[x][y] == '*')
        {
            y++;
            dir = 0 ;
        }
        return;
    }
}


int main(){
    int fx, fy, cx, cy, dirc = 0, dirf = 0,ans= 0;
    for (int j = 0; j < 10;j++){
            string line;
            getline(cin, line);
            mp[j] = line;
        
    }// 输入已完毕
    // 定义一下方向
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(mp[i][j] == 'C'){
                cx = i;
                cy = j;
            }
            if(mp[i][j] == 'F'){
                fx = i;
                fy = j;
            }
        }
    }
    while(!(cx == fx && cy ==fy)){
        run(cx,cy,dirc);
        run(fx, fy, dirf);
        ans++;
        hashval = cx + 10 * cy + 100 * dirc + 400 * (fx + 10 * fy + 100 * dirf);
        if(st.count(hashval)){
            cout << 0 << endl;
            return 0;
        }else
            st.emplace(hashval);
    }
    cout << ans << endl;
}