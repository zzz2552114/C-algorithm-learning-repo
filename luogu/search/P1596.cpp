#include<bits/stdc++.h>
using namespace std;

int n, m,nx,ny,ans = 0;
const int maxN = 105;
vector<string> mapl(maxN);
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int check[10010];

void dfs(int x,int y){
    if(y>=m || y< 0 || x>=n || x<0 || check[x+n*y])
        return;
    if(mapl[x][y] == '.')
        return;
        
    check[x + n * y] = 1;
    for (int i = 0; i < 8;i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        dfs(nx, ny);
    }
}


int main(){
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> mapl[i];
    }// 输入完毕
    for (int b = 0 ; b < n;b++){
        for (int c = 0; c < m;c++){
            if(!check[b+n*c] && mapl[b][c] == 'W'){
                dfs(b, c);
                ans++;
            }
        }
    }
    cout << ans << endl;
}