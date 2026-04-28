#include<iostream>
#include<vector>
using namespace std;
int r,c;
int mp[105][105],dp[105][105];

struct node{
    int x, y;
};
vector<node> dir{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int main(){
    cin >> r >> c;
    int minp = 1e9;
    node start;
    for (int i = 1; i <= r;i++){
        for (int j = 1; j <= c;j++){
            cin >> mp[i][j];
            if(mp[i][j]<minp){
                minp = mp[i][j];
                start = {i, j};
            }
        }
    }
    int stx = start.x , sty = start.y;
    dp[stx][sty] = 0;
    while(1){
        for (int i = 0; i < 4;i++){
            nxt = 
        }
    }
    
}