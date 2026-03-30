#include <bits/stdc++.h>
using namespace std;

int n,ans = 0;
const int Maxn = 210;
vector<vector<int>> isConnected(Maxn, vector<int>(Maxn));
stack<int> todo;
vector<bool> gone(Maxn,0);
bool flag = false;

void reback(){
    while(!todo.empty() && gone[todo.top()]==1){
        todo.pop();
    }
}

void pushin(int& i){
    flag = false;
    gone[i] = 1;
    for (int j = n-1; j > 0; j--)
    {
        if (isConnected[i][j] == 1 && (!gone[j]))
        {
            todo.push(j);
            flag = true;
        } // 现在把所有与i直接相连的都压栈了,而且栈顶是>i但离i最近的节点
    }
    if(!flag){
        // 回溯
        reback();
    }
    if(!todo.empty())
    {
        pushin(todo.top());
    }
}

int main(){
    // 题目的输入
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> isConnected[i][j];
        }
    }

    for (int i = 0; i<n;i++){
        if(gone[i])
            continue;
        pushin(i);
        ans++;
    }
    cout << ans << endl;
}